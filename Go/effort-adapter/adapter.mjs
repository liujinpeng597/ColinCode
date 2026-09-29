// adapter.mjs — 统一 reasoning_effort 抽象层
// low/medium/high/none → 各厂商原生思考参数（百炼 enable_thinking + thinking_budget / OpenAI reasoning_effort）
// 纯 Node 内置能力（fetch），零依赖。
//
// 用法：
//   const client = createClient({ provider: 'bailian', model: 'qwen3.8-max', effort: 'high' });
//   const r = await client.chat([{ role: 'user', content: 'hi' }]);
//   for await (const p of client.chatStream(msgs)) { ... }

export const DEFAULT_BUDGETS = { low: 512, medium: 4096, high: 16384 };
const EFFORTS = ['none', 'low', 'medium', 'high'];

// —— 模型思考能力识别 ——
// ponytail: 正则启发式有覆盖盲区；新模型/私有部署模型用 createClient({kinds: {'你的模型': 'hybrid'}}) 精确注册
const ONLY_RE = /deepseek-r1|qwq|glm-5\.3|minimax-m2\.5|k2\.7-code|k2-thinking|2\.4t-a95b|thinking/;
const NO_THINK_RE = /instruct|qwen3?-coder|deepseek-v3($|-)|qwen-(math|mt|doc|long)/;

export function thinkingKind(model, kinds = {}) {
  if (kinds[model]) return kinds[model];
  const m = String(model).toLowerCase();
  if (ONLY_RE.test(m)) return 'only';      // 仅思考：无法关闭
  if (NO_THINK_RE.test(m)) return 'none';  // 不支持思考
  return 'hybrid';                          // 混合：可开关（默认开关因模型而异）
}

// 核心映射：统一 effort → 厂商原生参数
export function buildThinkingParams(model, effort, { budgets = DEFAULT_BUDGETS, kinds } = {}) {
  if (effort == null) return {}; // 未指定 → 不注入，走服务端默认
  if (!EFFORTS.includes(effort)) throw new Error(`effort 必须是 ${EFFORTS.join('/')}, 收到: ${effort}`);
  const kind = thinkingKind(model, kinds);
  if (kind === 'only' && effort === 'none')
    throw new Error(`${model} 是仅思考模型, 无法关闭思考 (effort=none 不支持)`);
  if (kind === 'none') return {};                       // 模型不支持思考, 参数无意义
  if (kind === 'only') return { thinking_budget: budgets[effort] }; // 只能控预算
  if (effort === 'none') return { enable_thinking: false };         // 显式关, 抹平各家默认差异
  return { enable_thinking: true, thinking_budget: budgets[effort] };
}

export const PROVIDERS = {
  bailian: {
    name: 'bailian',
    baseURL: 'https://dashscope.aliyuncs.com/compatible-mode/v1',
    envKey: 'DASHSCOPE_API_KEY', // 新加坡地域改 baseURL 为 dashscope-intl.aliyuncs.com
    thinking: (model, effort, cfg) => buildThinkingParams(model, effort, cfg),
  },
  openai: {
    name: 'openai',
    baseURL: 'https://api.openai.com/v1',
    envKey: 'OPENAI_API_KEY',
    thinking: (model, effort) =>
      effort == null || effort === 'none' ? {} : { reasoning_effort: effort },
  },
};

export function createClient(opts = {}) {
  const prov = typeof opts.provider === 'string'
    ? (PROVIDERS[opts.provider] ?? { ...PROVIDERS.openai, name: opts.provider, envKey: 'API_KEY' }) // 任意 OpenAI 兼容端点: 传 provider 名 + baseURL + apiKey
    : (opts.provider ?? PROVIDERS.bailian);
  const cfg = {
    ...prov, // 先铺厂商默认, 再让下面的显式字段覆盖 (否则 prov.baseURL 会盖掉用户的 baseURL)
    baseURL: opts.baseURL ?? prov.baseURL,
    apiKey: opts.apiKey ?? process.env[prov.envKey ?? 'API_KEY'],
    model: opts.model,
    effort: opts.effort ?? null,
    budgets: { ...DEFAULT_BUDGETS, ...opts.budgets },
    kinds: opts.kinds ?? {},
    temperature: opts.temperature,
    maxTokens: opts.maxTokens,
    timeoutMs: opts.timeoutMs ?? 300_000, // 长思考流可能很慢
  };
  if (!cfg.model) throw new Error('必须指定 model');
  if (!cfg.apiKey) throw new Error(`缺少 API Key (设置环境变量 ${prov.envKey} 或传 apiKey)`);

  function buildBody(messages, c, stream) {
    const body = {
      model: c.model,
      messages,
      ...(prov.thinking?.(c.model, c.effort, c) ?? {}),
    };
    if (c.temperature != null) body.temperature = c.temperature;
    if (c.maxTokens != null) body.max_tokens = c.maxTokens; // OpenAI 推理模型需改用 max_completion_tokens
    if (stream) { body.stream = true; body.stream_options = { include_usage: true }; }
    return body;
  }

  async function request(body) {
    const res = await fetch(cfg.baseURL.replace(/\/$/, '') + '/chat/completions', {
      method: 'POST',
      headers: { 'content-type': 'application/json', authorization: `Bearer ${cfg.apiKey}` },
      body: JSON.stringify(body),
      signal: AbortSignal.timeout(cfg.timeoutMs),
    });
    if (!res.ok) {
      const text = await res.text();
      let msg = text;
      try { const j = JSON.parse(text); msg = j.error?.message ?? j.message ?? text; } catch {}
      throw new Error(`HTTP ${res.status}: ${msg}`);
    }
    return res;
  }

  function extractUsage(u = {}) {
    return {
      prompt: u.prompt_tokens,
      completion: u.completion_tokens,
      reasoning: u.output_tokens_details?.reasoning_tokens ?? u.completion_tokens_details?.reasoning_tokens,
      total: u.total_tokens,
    };
  }

  return {
    cfg,
    // 非流式
    async chat(messages, callOpts = {}) {
      const res = await request(buildBody(messages, { ...cfg, ...callOpts }, false));
      const data = await res.json();
      const msg = data.choices?.[0]?.message ?? {};
      return {
        content: msg.content ?? '',
        reasoning: msg.reasoning_content ?? msg.reasoning ?? '',
        usage: extractUsage(data.usage),
        raw: data,
      };
    },
    // 流式: 依次 yield {reasoning?} / {content?}, 最后 yield {usage}
    async *chatStream(messages, callOpts = {}) {
      const res = await request(buildBody(messages, { ...cfg, ...callOpts }, true));
      if (!res.body) throw new Error('响应无 body (不支持流式?)');
      let usage;
      for await (const line of sseDataLines(res.body)) {
        if (line === '[DONE]') break;
        let j; try { j = JSON.parse(line); } catch { continue; }
        if (j.usage) usage = extractUsage(j.usage);
        const d = j.choices?.[0]?.delta;
        if (d?.reasoning_content || d?.content) {
          yield { ...(d.reasoning_content && { reasoning: d.reasoning_content }),
                  ...(d.content && { content: d.content }) };
        }
      }
      if (usage) yield { usage };
    },
  };
}

// ponytail: 按 \n 切行只支持单行 data 事件; 各家 chat SSE 均为单行 JSON, 多行 data 需改为按空行分帧
async function* sseDataLines(body) {
  const dec = new TextDecoder();
  let buf = '';
  for await (const chunk of body) {
    buf += dec.decode(chunk, { stream: true });
    let nl;
    while ((nl = buf.indexOf('\n')) >= 0) {
      const line = buf.slice(0, nl).trimEnd();
      buf = buf.slice(nl + 1);
      if (line.startsWith('data:')) yield line.slice(5).trim();
    }
  }
}
