// adapter.test.mjs — 运行: node --test（本地 mock 服务端, 无需 API Key, 零依赖）
import { test } from 'node:test';
import assert from 'node:assert/strict';
import http from 'node:http';
import { createClient, buildThinkingParams, thinkingKind } from './adapter.mjs';

async function withMock(handler, fn) {
  const srv = http.createServer(handler);
  await new Promise((r) => srv.listen(0, '127.0.0.1', r));
  try { return await fn(`http://127.0.0.1:${srv.address().port}/v1`); }
  finally { srv.close(); }
}

// 1. 核心映射（表驱动）
test('buildThinkingParams: effort → 厂商参数', () => {
  const cases = [
    ['qwen3.8-max', 'low',    { enable_thinking: true, thinking_budget: 512 }],
    ['qwen3.8-max', 'medium', { enable_thinking: true, thinking_budget: 4096 }],
    ['qwen3.8-max', 'high',   { enable_thinking: true, thinking_budget: 16384 }],
    ['qwen-plus',   'none',   { enable_thinking: false }],       // 抹平默认差异: 显式关
    ['deepseek-r1', 'high',   { thinking_budget: 16384 }],        // 仅思考模型: 只控预算
    ['deepseek-r1', 'none',   null],                              // 仅思考模型关不掉 → 抛错
    ['qwen3-235b-a22b-instruct-2507', 'high', {}],                // 不支持思考 → 不注入
    ['any-model',   null,     {}],                                // 未指定 → 不注入
  ];
  for (const [model, effort, want] of cases) {
    if (want === null) { assert.throws(() => buildThinkingParams(model, effort), undefined, `${model}/${effort}`); continue; }
    assert.deepEqual(buildThinkingParams(model, effort), want, `${model}/${effort}`);
  }
  // 自定义预算 + kinds 覆盖
  assert.deepEqual(
    buildThinkingParams('my-model', 'low', { budgets: { low: 1024 }, kinds: { 'my-model': 'hybrid' } }),
    { enable_thinking: true, thinking_budget: 1024 });
});

test('thinkingKind: 模型能力识别', () => {
  assert.equal(thinkingKind('deepseek-r1'), 'only');
  assert.equal(thinkingKind('qwq-plus'), 'only');
  assert.equal(thinkingKind('glm-5.3'), 'only');
  assert.equal(thinkingKind('kimi-k2.7-code'), 'only');
  assert.equal(thinkingKind('deepseek-v3'), 'none');
  assert.equal(thinkingKind('deepseek-v3.2'), 'hybrid');
  assert.equal(thinkingKind('qwen3-coder-plus'), 'none');
  assert.equal(thinkingKind('qwen3.8-max'), 'hybrid');
  assert.equal(thinkingKind('unknown-model', { 'unknown-model': 'only' }), 'only'); // kinds 覆盖
});

// 2. 百炼流式: 验证请求注入 + SSE 解析 + usage 提取（端到端）
test('bailian chatStream: 注入思考参数并解析 SSE', () => withMock((req, res) => {
  let raw = '';
  req.on('data', (c) => (raw += c));
  req.on('end', () => {
    const body = JSON.parse(raw);
    assert.equal(body.model, 'qwen3.8-max');
    assert.equal(body.enable_thinking, true);          // 关键: effort=low 已映射
    assert.equal(body.thinking_budget, 512);
    assert.equal(body.stream, true);
    assert.equal(req.headers.authorization, 'Bearer test-key');
    res.writeHead(200, { 'content-type': 'text/event-stream' });
    const events = [
      { choices: [{ delta: { reasoning_content: '思考片段' } }] },
      { choices: [{ delta: { content: '正', } }] },
      { choices: [{ delta: { content: '文' } }] },
      { choices: [], usage: { prompt_tokens: 3, completion_tokens: 9, total_tokens: 12,
        output_tokens_details: { reasoning_tokens: 6 } } },
    ];
    for (const e of events) res.write(`data: ${JSON.stringify(e)}\n\n`);
    res.write('data: [DONE]\n\n');
    res.end();
  });
}, async (base) => {
  const client = createClient({ provider: 'bailian', baseURL: base, apiKey: 'test-key',
    model: 'qwen3.8-max', effort: 'low' });
  const parts = [];
  for await (const p of client.chatStream([{ role: 'user', content: 'hi' }])) parts.push(p);
  assert.deepEqual(parts, [
    { reasoning: '思考片段' },
    { content: '正' },
    { content: '文' },
    { usage: { prompt: 3, completion: 9, reasoning: 6, total: 12 } },
  ]);
}));

// 3. OpenAI 非流式: 验证 reasoning_effort 透传 + message 解析
test('openai chat: 透传 reasoning_effort', () => withMock((req, res) => {
  let raw = '';
  req.on('data', (c) => (raw += c));
  req.on('end', () => {
    const body = JSON.parse(raw);
    assert.deepEqual(body.reasoning_effort, 'high');
    assert.equal('enable_thinking' in body, false);
    res.writeHead(200, { 'content-type': 'application/json' });
    res.end(JSON.stringify({
      choices: [{ message: { content: 'ok', reasoning_content: 'why' } }],
      usage: { prompt_tokens: 1, completion_tokens: 2, total_tokens: 3,
        completion_tokens_details: { reasoning_tokens: 2 } },
    }));
  });
}, async (base) => {
  const client = createClient({ provider: 'openai', baseURL: base, apiKey: 'test-key',
    model: 'gpt-5', effort: 'high' });
  const r = await client.chat([{ role: 'user', content: 'hi' }]);
  assert.equal(r.content, 'ok');
  assert.equal(r.reasoning, 'why');
  assert.deepEqual(r.usage, { prompt: 1, completion: 2, reasoning: 2, total: 3 });
}));

// 4. 仅思考模型 + effort=none: 抛出明确错误
test('仅思考模型无法关闭思考', () => {
  assert.throws(() => buildThinkingParams('deepseek-r1', 'none'), /仅思考模型/);
});

// 5. 缺少 API Key: 快速失败
test('缺少 API Key 时报错', () => {
  const saved = process.env.DASHSCOPE_API_KEY;
  delete process.env.DASHSCOPE_API_KEY;
  assert.throws(() => createClient({ model: 'qwen3.8-max' }), /缺少 API Key/);
  if (saved) process.env.DASHSCOPE_API_KEY = saved;
});
