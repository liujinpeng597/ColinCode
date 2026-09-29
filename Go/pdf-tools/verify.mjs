import fs from 'node:fs';
import path from 'node:path';
import { createRequire } from 'node:module';

const require = createRequire(import.meta.url);
const { getDocument, GlobalWorkerOptions } = await import('pdfjs-dist/legacy/build/pdf.mjs');

// 尝试加载 worker，若失败则退回主线程假 worker
try {
  const { default: PdfWorker } = await import('pdfjs-dist/legacy/build/pdf.worker.mjs');
  GlobalWorkerOptions.workerPort = new PdfWorker();
} catch (e) {
  // ignore
}

const pdfPath = 'C:/Users/24191/Desktop/Colin/Go/Golang核心知识点清单.pdf';
const bytes = new Uint8Array(fs.readFileSync(pdfPath));

const task = getDocument({ data: bytes, useWorkerFetch: false, isEvalSupported: false });
const pdf = await task.promise;
console.log('pages:', pdf.numPages);

for (let i = 1; i <= pdf.numPages; i++) {
  const page = await pdf.getPage(i);
  const tc = await page.getTextContent();
  const text = tc.items.map((it) => it.str).join('');
  console.log(`\n===== PAGE ${i} =====`);
  console.log(text.slice(0, 600));
}

// 尝试渲染成 PNG
let renderOk = false;
try {
  const { createCanvas } = require('@napi-rs/canvas');
  for (let i = 1; i <= pdf.numPages; i++) {
    const page = await pdf.getPage(i);
    const viewport = page.getViewport({ scale: 2 });
    const canvas = createCanvas(Math.ceil(viewport.width), Math.ceil(viewport.height));
    const ctx = canvas.getContext('2d');
    await page.render({ canvasContext: ctx, viewport }).promise;
    const buf = canvas.toBuffer('image/png');
    fs.writeFileSync(`C:/Users/24191/Desktop/Colin/Go/pdf-tools/page${i}.png`, buf);
  }
  renderOk = true;
  console.log('\nRENDER OK');
} catch (e) {
  console.log('\nRENDER FAILED:', e.message);
}

console.log('\nrenderOk:', renderOk);
