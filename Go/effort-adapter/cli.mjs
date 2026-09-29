#!/usr/bin/env node
// cli.mjs — 演示/试用入口
// 用法:
//   node cli.mjs "你的问题"
//   node cli.mjs --model qwen3.8-max --effort high "9.9 和 9.11 谁大?"
//   node cli.mjs --provider openai --model gpt-5 --effort low "hi"
//   node cli.mjs --effort none --no-stream "闲聊"
// API Key 从环境变量读: DASHSCOPE_API_KEY (百炼) / OPENAI_API_KEY (OpenAI)
import { createClient } from './adapter.mjs';

const opts = { positional: [] };
const args = process.argv.slice(2);
for (let i = 0; i < args.length; i++) {
  const a = args[i];
  if (a === '--no-stream') opts.noStream = true;
  else if (a.startsWith('--')) opts[a.slice(2)] = args[++i];
  else opts.positional.push(a);
}
const provider = opts.provider ?? 'bailian';
const effort = opts.effort ?? 'medium';
const model = opts.model ?? (provider === 'openai' ? 'gpt-5' : 'qwen3.8-max');
const prompt = opts.positional.join(' ') || '9.9 和 9.11 谁大?';

let client;
try {
  client = createClient({ provider, model, effort, baseURL: opts.baseURL, apiKey: opts.apiKey });
} catch (e) {
  console.error(`✗ ${e.message}`);
  process.exit(1);
}

const msgs = [{ role: 'user', content: prompt }];
let shownAnswer = false;
const showUsage = (u) =>
  console.error(`\n[usage] 输入 ${u.prompt} · 输出 ${u.completion} (含思考 ${u.reasoning ?? 0}) · 共 ${u.total} tokens`);

try {
  if (opts.noStream) {
    const r = await client.chat(msgs);
    if (r.reasoning) console.log(`·· 思考 ··\n${r.reasoning}\n`);
    console.log(r.content);
    showUsage(r.usage);
  } else {
    process.stdout.write('·· 思考 ·· ');
    for await (const p of client.chatStream(msgs)) {
      if (p.reasoning) process.stdout.write(p.reasoning);
      if (p.content && !shownAnswer) { shownAnswer = true; process.stdout.write(`\n\n—— 回答 ——\n`); }
      if (p.content) process.stdout.write(p.content);
      if (p.usage) showUsage(p.usage);
    }
    if (!shownAnswer) process.stdout.write('\n');
  }
} catch (e) {
  console.error(`✗ ${e.message}`);
  process.exit(1);
}
