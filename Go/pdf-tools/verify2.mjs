import fs from 'node:fs';
import { getDocument, GlobalWorkerOptions } from 'pdfjs-dist/legacy/build/pdf.mjs';

try {
  const { default: PdfWorker } = await import('pdfjs-dist/legacy/build/pdf.worker.mjs');
  GlobalWorkerOptions.workerPort = new PdfWorker();
} catch (e) {}

const pdfPath = 'C:/Users/24191/Desktop/Colin/Go/Golang核心知识点清单.pdf';
const bytes = new Uint8Array(fs.readFileSync(pdfPath));
const pdf = await getDocument({ data: bytes, useWorkerFetch: false, isEvalSupported: false }).promise;

const PAGE_W = 595.28, PAGE_H = 841.89;
const LEFT = 58, RIGHT = 595.28 - 58; // 内容左右边界

let allOk = true;
for (let i = 1; i <= pdf.numPages; i++) {
  const page = await pdf.getPage(i);
  const tc = await page.getTextContent();
  const fullText = tc.items.map((it) => it.str).join('');
  const hasFooter = fullText.includes(`第 ${i} 页 / 共 ${pdf.numPages} 页`);

  let minLeft = Infinity, maxRight = -Infinity;
  for (const it of tc.items) {
    if (!it.str) continue;
    const x = it.transform[4];
    const w = it.width || 0;
    minLeft = Math.min(minLeft, x);
    maxRight = Math.max(maxRight, x + w);
  }

  const overflowRight = maxRight > RIGHT + 2;
  const overflowLeft = minLeft < LEFT - 2;
  const ok = hasFooter && !overflowRight && !overflowLeft;
  if (!ok) allOk = false;

  console.log(
    `page ${i}: footer=${hasFooter} ` +
    `L=${minLeft.toFixed(1)} R=${maxRight.toFixed(1)} ` +
    `[overflow R=${overflowRight} L=${overflowLeft}] ${ok ? 'OK' : 'ISSUE'}`
  );
}
console.log('\nALL OK:', allOk);
