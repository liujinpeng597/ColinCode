// Golang 核心知识点清单 PDF 生成脚本
// 依赖：pdfkit + fontkit；中文字体：微软雅黑（正文）与微软雅黑粗体（标题）
'use strict';

const fs = require('fs');
const path = require('path');
const PDFDocument = require('pdfkit');
const fontkit = require('fontkit');

// ---------------- 字体加载 ----------------
function openTtcFace(ttcPath, postscriptName) {
  const coll = fontkit.openSync(ttcPath);
  if (coll.fonts) {
    return (postscriptName && coll.getFont(postscriptName)) || coll.fonts[0];
  }
  return coll;
}

const FONT_DIR = 'C:/Windows/Fonts';
const regularFont = openTtcFace(path.join(FONT_DIR, 'msyh.ttc'), 'MicrosoftYaHei');
const boldFont = openTtcFace(path.join(FONT_DIR, 'msyhbd.ttc'), 'MicrosoftYaHei-Bold');

let monoFont = null;
const consolasPath = path.join(FONT_DIR, 'consola.ttf');
if (fs.existsSync(consolasPath)) {
  try {
    monoFont = fontkit.openSync(consolasPath);
  } catch (e) {
    monoFont = null;
  }
}

// ---------------- 排版常量 ----------------
const PAGE = { width: 595.28, height: 841.89 }; // A4
const MARGIN = { left: 58, right: 58, top: 66, bottom: 60 };

const COLOR = {
  text: '#2B2B33',
  term: '#0F4C5C',
  heading: '#0E7490',
  accent: '#00ADD8',
  muted: '#8A8F98',
  code: '#B45309',
};

const FONT = {
  title: 24,
  subtitle: 11,
  outline: 10.5,
  h2: 15,
  h3: 12.5,
  body: 10.5,
  footer: 9,
};

const LINE_GAP = 4.5;
const PARA_AFTER_BULLET = 3.2;
const SPACE = { beforeH2: 18, afterH2: 7, beforeH3: 10, afterH3: 4 };

// ---------------- 内容数据 ----------------
const content = [
  {
    type: 'title',
    main: 'Golang 核心知识点清单',
    sub: '从零基础到进阶 · 系统化语言知识脉络',
  },
  {
    type: 'outline',
    items: [
      '一、基础语法',
      '二、函数与指针',
      '三、核心数据结构',
      '四、类型与面向对象抽象',
      '五、并发编程基础',
      '六、错误处理',
      '七、高级特性与工程化',
    ],
  },

  // ============ 一、基础语法 ============
  { type: 'h2', text: '一、基础语法' },

  { type: 'h3', text: '1.1 变量与常量声明' },
  {
    type: 'bullets',
    items: [
      { t: 'var 关键字声明', d: '使用 `var` 关键字声明变量，形如“var 名称 类型 = 值”，类型可省略由编译器自动推断。' },
      { t: '短变量声明', d: '在函数内部使用 `:=` 声明并初始化变量，类型自动推断，是最常用的写法。' },
      { t: '批量声明', d: '使用 `var (...)` 语法一次性声明多个变量，使声明集中、整洁。' },
      { t: '常量声明', d: '使用 `const` 声明不可修改的值，支持 iota 常量生成器批量递增赋值。' },
    ],
  },

  { type: 'h3', text: '1.2 基本数据类型' },
  {
    type: 'bullets',
    items: [
      { t: '整型', d: '包括有符号 `int`、`int8/16/32/64` 与无符号 `uint`、`uint8/16/32/64` 以及 `uintptr`。' },
      { t: '浮点型', d: '`float32` 与 `float64` 用于存储带小数的数值，运算结果可能产生精度误差。' },
      { t: '布尔型', d: '`bool` 类型只有 `true` 与 `false` 两个取值，不能与数值互转。' },
      { t: '字符串', d: '`string` 是不可变的 UTF-8 字节序列，可用双引号或反引号表示。' },
      { t: '零值', d: '未显式初始化的变量自动获得其类型的零值，如数值为 0、字符串为 ""、布尔为 false。' },
      { t: '显式类型转换', d: 'Go 不支持隐式转换，需用 `T(v)` 形式显式转换，保证类型安全。' },
    ],
  },

  { type: 'h3', text: '1.3 控制结构' },
  {
    type: 'bullets',
    items: [
      { t: 'if / else', d: '条件分支结构，条件表达式无需括号，且支持在条件前加简短初始化语句。' },
      { t: 'for 循环', d: 'Go 中唯一的循环语句，可表达经典三段式、while 式与无限循环三种形式。' },
      { t: 'switch', d: '多分支选择结构，默认不贯穿（无需 break），支持无表达式的条件 switch。' },
      { t: 'select', d: '在多个通道操作中选择一个可执行的分支执行，是并发编程的核心控制结构。' },
    ],
  },

  // ============ 二、函数与指针 ============
  { type: 'h2', text: '二、函数与指针' },

  { type: 'h3', text: '2.1 函数定义与多返回值' },
  {
    type: 'bullets',
    items: [
      { t: '函数定义', d: '使用 `func` 关键字定义函数，参数与返回值均需显式声明类型。' },
      { t: '多返回值', d: '函数可同时返回多个值，最典型的是“结果 + error”的组合。' },
      { t: '命名返回值', d: '为返回值命名后可在函数体内直接赋值，并简化 return 语句。' },
      { t: '可变参数', d: '使用 `...T` 接收不定数量的参数，在函数内部以切片形式访问。' },
    ],
  },

  { type: 'h3', text: '2.2 匿名函数与闭包' },
  {
    type: 'bullets',
    items: [
      { t: '匿名函数', d: '没有名字的函数，可赋值给变量、作为参数传递或立即执行。' },
      { t: '闭包', d: '函数可捕获并引用其外部作用域的变量，即使外部函数已返回仍可访问。' },
    ],
  },

  { type: 'h3', text: '2.3 defer 延迟调用' },
  {
    type: 'bullets',
    items: [
      { t: 'defer 机制', d: '将函数调用推迟到外层函数返回前执行，常用于资源释放与解锁。' },
      { t: '执行顺序', d: '多个 defer 按后进先出（LIFO）顺序执行，即最后 defer 的最先执行。' },
    ],
  },

  { type: 'h3', text: '2.4 指针' },
  {
    type: 'bullets',
    items: [
      { t: '指针概念', d: '指针存储另一变量的内存地址，用 `*T` 表示类型、`&` 取地址。' },
      { t: '解引用', d: '使用 `*p` 读取或修改指针所指向变量的值。' },
      { t: '使用场景', d: '在函数间传递大对象、修改外部变量，以及表达“可为空”的引用语义。' },
      { t: 'new 分配', d: '使用 `new(T)` 分配内存并返回指向该类型零值的指针。' },
    ],
  },

  // ============ 三、核心数据结构 ============
  { type: 'h2', text: '三、核心数据结构' },

  { type: 'h3', text: '3.1 数组与切片' },
  {
    type: 'bullets',
    items: [
      { t: '数组（Array）', d: '长度固定且同类型的元素集合，数组长度是其类型的一部分。' },
      { t: '切片（Slice）', d: '长度可变的动态视图，由指向底层数组的指针、长度与容量三部分组成。' },
      { t: '切片创建', d: '通过 make、字面量或对数组 / 切片进行切片操作来创建。' },
      { t: 'append 追加', d: '向切片末尾追加元素，容量不足时自动扩容并返回新切片。' },
      { t: 'copy 复制', d: '在两个切片之间复制元素，复制长度为两者中的较小值。' },
      { t: '两者区别', d: '数组长度固定且为值类型（赋值即拷贝），切片长度可变且共享底层数组。' },
    ],
  },

  { type: 'h3', text: '3.2 映射（Map）' },
  {
    type: 'bullets',
    items: [
      { t: '定义', d: 'map 是无序的键值对集合，使用 `map[K]V` 声明键与值的类型。' },
      { t: '创建', d: '使用 make 或字面量初始化 map，未初始化的 map 为 nil。' },
      { t: '增删改查', d: '通过下标读写元素、用 delete 删除；读取时用第二个返回值判断键是否存在。' },
      { t: '遍历', d: '使用 `for range` 遍历键值对，遍历顺序不保证固定。' },
    ],
  },

  // ============ 四、类型与面向对象抽象 ============
  { type: 'h2', text: '四、类型与面向对象抽象' },

  { type: 'h3', text: '4.1 结构体与方法' },
  {
    type: 'bullets',
    items: [
      { t: '结构体（Struct）', d: '用 `type` 与 `struct` 定义复合类型，将多个相关字段聚合到一起。' },
      { t: '字段访问', d: '使用点号 `.` 访问或修改结构体字段，也可取字段地址赋值。' },
      { t: '方法（Method）', d: '为自定义类型绑定函数，接收者可声明为值类型或指针类型。' },
      { t: '指针接收者', d: '使用指针接收者可修改接收者本身并避免大对象拷贝，是更常用的写法。' },
    ],
  },

  { type: 'h3', text: '4.2 接口' },
  {
    type: 'bullets',
    items: [
      { t: '接口定义', d: '接口声明一组方法签名，描述“能做什么”而不涉及具体实现。' },
      { t: '隐式实现', d: '类型只要实现了接口的全部方法即自动满足该接口，无需显式声明。' },
      { t: '空接口', d: '`interface{}` 可持有任意类型的值，是泛型出现前的通用容器。' },
    ],
  },

  { type: 'h3', text: '4.3 类型断言' },
  {
    type: 'bullets',
    items: [
      { t: '类型断言', d: '使用 `x.(T)` 将接口值断言为具体类型，失败时会触发 panic。' },
      { t: '安全断言', d: '使用 `v, ok := x.(T)` 判断断言是否成功，避免直接 panic。' },
      { t: 'type switch', d: '用 switch 配合类型断言，按动态类型对接口值分情况处理。' },
    ],
  },

  // ============ 五、并发编程基础 ============
  { type: 'h2', text: '五、并发编程基础' },

  { type: 'h3', text: '5.1 协程（Goroutine）' },
  {
    type: 'bullets',
    items: [
      { t: '启动方式', d: '在函数调用前加 `go` 关键字即可创建一个并发执行的 goroutine。' },
      { t: '轻量特性', d: 'goroutine 由 Go 运行时调度，栈可动态增长，开销远小于操作系统线程。' },
    ],
  },

  { type: 'h3', text: '5.2 通道（Channel）' },
  {
    type: 'bullets',
    items: [
      { t: '通道概念', d: 'channel 是 goroutine 之间通信的管道，使用 `make(chan T)` 创建。' },
      { t: '无缓冲通道', d: '发送与接收必须同步配对，天然提供同步语义。' },
      { t: '有缓冲通道', d: '可缓存一定数量的元素，缓冲区未满 / 非空时发送 / 接收不阻塞。' },
      { t: '关闭通道', d: '使用 `close` 关闭通道，接收方可据此判断通道已关闭。' },
      { t: '通道方向', d: '可为通道参数指定只发送或只接收方向，即 `chan<-` 与 `<-chan`。' },
    ],
  },

  { type: 'h3', text: '5.3 基本并发控制' },
  {
    type: 'bullets',
    items: [
      { t: 'sync.WaitGroup', d: '用于等待一组 goroutine 完成，通过 Add / Done / Wait 协调。' },
      { t: 'sync.Mutex', d: '互斥锁，通过 Lock / Unlock 保护共享资源，避免数据竞争。' },
      { t: '数据竞争', d: '多个 goroutine 并发读写同一变量且未同步时，会产生不确定的结果。' },
    ],
  },

  // ============ 六、错误处理 ============
  { type: 'h2', text: '六、错误处理' },

  { type: 'h3', text: '6.1 Error 接口' },
  {
    type: 'bullets',
    items: [
      { t: 'error 接口', d: '内置接口仅包含 `Error() string` 一个方法，任何实现它的类型都是错误。' },
      { t: '创建错误', d: '使用 `errors.New` 或 `fmt.Errorf` 创建错误值。' },
      { t: '错误传播', d: '函数通过多返回值将错误返回给调用者，由调用者判断并处理。' },
      { t: '错误包装', d: '使用 `fmt.Errorf` 的 `%w` 包装底层错误，`errors.Is / As` 用于解包判断。' },
    ],
  },

  { type: 'h3', text: '6.2 Panic 与 Recover' },
  {
    type: 'bullets',
    items: [
      { t: 'panic', d: '表示程序无法继续运行的严重错误，触发后沿调用栈向上传播。' },
      { t: 'recover', d: '仅在 defer 中调用可捕获 panic 并让程序恢复执行。' },
      { t: '使用原则', d: 'panic 用于不可恢复的致命错误，常规错误应通过返回值处理。' },
    ],
  },

  // ============ 七、高级特性与工程化 ============
  { type: 'h2', text: '七、高级特性与工程化' },

  { type: 'h3', text: '7.1 泛型（Generics）' },
  {
    type: 'bullets',
    items: [
      { t: '泛型概念', d: '使用类型参数让函数与类型可复用，Go 1.18 起支持。' },
      { t: '类型约束', d: '通过 interface 定义类型参数必须满足的约束，如 `any`、`comparable`。' },
    ],
  },

  { type: 'h3', text: '7.2 反射（Reflection）' },
  {
    type: 'bullets',
    items: [
      { t: 'reflect 包', d: '提供在运行时检查类型与值的机制。' },
      { t: '常用操作', d: '`reflect.TypeOf` 获取类型，`reflect.ValueOf` 获取并操作值。' },
      { t: '使用场景', d: '用于序列化、通用框架等需处理未知类型的情况，但性能较低应谨慎使用。' },
    ],
  },

  { type: 'h3', text: '7.3 Go Modules 包管理' },
  {
    type: 'bullets',
    items: [
      { t: 'go mod init', d: '初始化模块并生成 go.mod 文件，声明模块路径。' },
      { t: '依赖管理', d: '`go get` 添加依赖，`go mod tidy` 清理并同步依赖。' },
      { t: 'go.sum 校验', d: '记录依赖的校验和，保证构建可复现、可验证。' },
    ],
  },

  { type: 'h3', text: '7.4 常用标准库' },
  {
    type: 'bullets',
    items: [
      { t: 'fmt', d: '格式化输入输出，如 `Printf`、`Sprintf`、`Scanf`。' },
      { t: 'io', d: '定义 `Reader / Writer` 等基本 I/O 接口，是流式处理的基础。' },
      { t: 'net/http', d: '构建 HTTP 客户端与服务端，用于 Web 服务开发。' },
      { t: 'encoding/json', d: '在 JSON 与 Go 数据结构之间进行序列化与反序列化。' },
    ],
  },

  { type: 'h3', text: '7.5 编写测试' },
  {
    type: 'bullets',
    items: [
      { t: 'testing 包', d: '内置测试框架，测试函数以 `Test` 开头并接收 `*testing.T`。' },
      { t: 'go test 命令', d: '运行测试，支持单元测试、基准测试与示例测试。' },
      { t: '表驱动测试', d: '将多组输入输出放入表格循环执行，是 Go 社区推荐的测试风格。' },
    ],
  },
];

// ---------------- 渲染辅助 ----------------
function splitInline(text) {
  const out = [];
  const parts = text.split('`');
  parts.forEach((p, i) => {
    if (p === '') return;
    out.push({ text: p, code: i % 2 === 1 });
  });
  return out;
}

function isAscii(str) {
  for (let i = 0; i < str.length; i++) {
    if (str.charCodeAt(i) > 127) return false;
  }
  return true;
}

function renderRuns(doc, runs, opts) {
  runs.forEach((r, i) => {
    const isFirst = i === 0;
    const isLast = i === runs.length - 1;
    doc.font(r.font).fontSize(opts.size).fillColor(r.color);
    if (isFirst) {
      doc.text(r.text, opts.x, doc.y, {
        width: opts.width,
        lineGap: opts.lineGap,
        continued: !isLast,
      });
    } else if (isLast) {
      doc.text(r.text, { width: opts.width, continued: false });
    } else {
      doc.text(r.text, { width: opts.width, continued: true });
    }
  });
}

function ensureSpace(doc, needed) {
  const bottom = PAGE.height - MARGIN.bottom;
  if (doc.y + needed > bottom) {
    doc.addPage();
  }
}

// ---------------- 构建 PDF ----------------
const outPath = path.join(__dirname, '..', 'Golang核心知识点清单.pdf');
const doc = new PDFDocument({
  size: [PAGE.width, PAGE.height],
  margins: MARGIN,
  autoFirstPage: false,
  bufferPages: true,
  info: {
    Title: 'Golang 核心知识点清单',
    Author: '编程讲师 · 知识清单',
    Subject: 'Golang 从零基础到进阶的系统化知识点清单',
  },
});

doc.registerFont('body', regularFont);
doc.registerFont('bold', boldFont);
if (monoFont) doc.registerFont('code', monoFont);

const stream = fs.createWriteStream(outPath);
doc.pipe(stream);

doc.addPage();

const contentWidth = PAGE.width - MARGIN.left - MARGIN.right;
let pageIndex = 0;

function renderTitle(node) {
  doc.font('bold').fontSize(FONT.title).fillColor(COLOR.heading);
  doc.text(node.main, MARGIN.left, MARGIN.top, { width: contentWidth, align: 'center' });

  const ruleY = doc.y + 8;
  doc.save().moveTo(PAGE.width / 2 - 90, ruleY).lineTo(PAGE.width / 2 + 90, ruleY)
    .lineWidth(1.2).strokeColor(COLOR.accent).stroke().restore();

  doc.y = ruleY + 10;
  doc.font('body').fontSize(FONT.subtitle).fillColor(COLOR.muted);
  doc.text(node.sub, MARGIN.left, doc.y, { width: contentWidth, align: 'center' });
  doc.y += 6;
}

function renderOutline(items) {
  doc.y += 14;
  const startY = doc.y;
  const colW = contentWidth / 2;
  items.forEach((item, i) => {
    const col = i % 2;
    const row = Math.floor(i / 2);
    const x = MARGIN.left + col * colW;
    const y = startY + row * 22;
    doc.font('bold').fontSize(FONT.outline).fillColor(COLOR.accent);
    doc.text('▪ ', x, y, { continued: true, width: 14 });
    doc.font('body').fillColor(COLOR.text);
    doc.text(item, { width: colW - 14, lineBreak: false });
  });
  doc.y = startY + Math.ceil(items.length / 2) * 22 + 12;
}

function renderH2(node) {
  ensureSpace(doc, FONT.h2 + SPACE.beforeH2 + SPACE.afterH2 + 20);
  doc.y += SPACE.beforeH2;
  doc.font('bold').fontSize(FONT.h2).fillColor(COLOR.heading);
  doc.text(node.text, MARGIN.left, doc.y, { width: contentWidth });
  // 标题下细线
  const lineY = doc.y + 4;
  doc.save().moveTo(MARGIN.left, lineY).lineTo(PAGE.width - MARGIN.right, lineY)
    .lineWidth(0.7).strokeColor('#D5DBE0').stroke().restore();
  doc.y = lineY + SPACE.afterH2;
}

function renderH3(node) {
  ensureSpace(doc, FONT.h3 + SPACE.beforeH3 + SPACE.afterH3 + 20);
  doc.y += SPACE.beforeH3;
  doc.font('bold').fontSize(FONT.h3).fillColor(COLOR.term);
  doc.text(node.text, MARGIN.left, doc.y, { width: contentWidth });
  doc.y += SPACE.afterH3;
}

function renderBullets(node) {
  node.items.forEach((item) => {
    const runs = [
      { text: '▪  ', font: 'body', color: COLOR.accent },
      { text: item.t + '：', font: 'bold', color: COLOR.term },
    ];
    for (const seg of splitInline(item.d)) {
      const useMono = seg.code && monoFont && isAscii(seg.text);
      runs.push({
        text: seg.text,
        font: useMono ? 'code' : 'body',
        color: seg.code ? COLOR.code : COLOR.text,
      });
    }
    ensureSpace(doc, FONT.body + LINE_GAP + 4);
    renderRuns(doc, runs, {
      x: MARGIN.left,
      width: contentWidth,
      size: FONT.body,
      lineGap: LINE_GAP,
    });
    doc.y += PARA_AFTER_BULLET;
  });
}

for (const node of content) {
  switch (node.type) {
    case 'title': renderTitle(node); break;
    case 'outline': renderOutline(node.items); break;
    case 'h2': renderH2(node); break;
    case 'h3': renderH3(node); break;
    case 'bullets': renderBullets(node); break;
    default: break;
  }
}

// 页脚（页码）
const pageCount = doc.bufferedPageRange().count;
for (let i = 0; i < pageCount; i++) {
  doc.switchToPage(i);
  // 临时放开底部边距，使页脚可绘制在页边距区域而不触发自动分页
  doc.page.margins.bottom = 0;
  const footerY = PAGE.height - MARGIN.bottom + 22;
  doc.font('body').fontSize(FONT.footer).fillColor(COLOR.muted);
  doc.text('Golang 核心知识点清单', MARGIN.left, footerY, {
    width: contentWidth / 2, align: 'left', lineBreak: false,
  });
  doc.text(`第 ${i + 1} 页 / 共 ${pageCount} 页`, MARGIN.left + contentWidth / 2, footerY, {
    width: contentWidth / 2, align: 'right', lineBreak: false,
  });
  doc.page.margins.bottom = MARGIN.bottom;
}

doc.end();

stream.on('finish', () => {
  const bytes = fs.statSync(outPath).size;
  console.log('PDF generated:', outPath);
  console.log('Size:', (bytes / 1024).toFixed(1), 'KB');
  console.log('Pages:', pageCount);
});
