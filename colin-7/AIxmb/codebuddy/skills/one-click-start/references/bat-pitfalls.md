# BAT Pitfalls

## 已记录问题

### LF-only 换行

Windows `cmd.exe` 对 LF-only 批处理文件的解析可能把多行命令粘在一起，出现 `'n' is not recognized`、`'ip' is not recognized` 或 `was unexpected at this time`。生成或修改 `.bat` 后必须转换为 CRLF，并检查不存在裸 LF。

### 代码块内的括号

`if (...)` 和 `for (...)` 会先解析整个代码块。即使分支不会执行，块内 `echo Install (first run) ...`、`echo PID=(...)` 或 `echo URL (http://...)` 也可能破坏语法。优先删除这些括号，或使用 `^(`、`^)` 转义。

### 窗口一闪而过

依赖安装、服务启动或健康检查失败后，批处理如果直接 `exit /b`，双击窗口会立即消失。统一失败标签必须显示错误并 `pause`；成功时至少显示子服务日志窗口和访问地址，必要时也暂停主窗口。

### Vite 的 localhost 与 IPv4

Vite 默认的 `localhost` 可能监听 `[::1]`。如果脚本检查或打开 `127.0.0.1`，会误报前端未启动。使用 `npm run dev -- --host 127.0.0.1`，并让健康检查与浏览器地址使用同一个地址。

### `start` 的路径和引号

不要依赖当前目录，也不要把带空格的路径直接拼进复杂的 `cmd /k` 字符串。用 `/D "%ROOT%\backend"` 或 `/D "%ROOT%\frontend"` 设置工作目录，再使用相对命令启动；执行后检查 `errorlevel`。

### `%~dp0` 末尾反斜杠与引号

`%~dp0` 本身以反斜杠结尾。直接拼成 `"%ROOT%\backend"` 会得到双反斜杠；更危险的是把以反斜杠结尾的路径直接放进引号（如 `start /D "C:\path\" cmd /k ...`），`\"` 会被 `cmd.exe` 当成转义引号，引号就此失配、后续参数全部错位。统一先 `set "ROOT=%~dp0"` 并去掉尾部 `\` 再拼接。

### 用窗口标题识别进程

`start "Title"` 打开的控制台窗口，标题常被宿主进程改写（例如 `cmd.exe - npm run dev`），不一定等于自定义的 `Title`，因此 `taskkill /FI "WINDOWTITLE eq ..."` 经常匹配不到。识别进程应以端口为准：用 `netstat -ano` 找出监听目标端口的 PID，校验该 PID 的可执行文件确为本项目运行时后再关闭，否则不动它。

### 错误码与重定向

`start` 可能沿用前一个命令的 `errorlevel`，测试脚本时不要用 `< NUL` 模拟按键，因为 `timeout` 会因此失败。真实验证应在交互式 `cmd.exe` 中运行，或为测试提供明确的非交互模式。

### 端口探测的 findstr 把 errorlevel 传给 start（实测）

现象：端口空闲时脚本正常拉起服务，却立刻打印“could not launch the backend process”并以 1 退出，同时服务其实已经启动成功。

原因：`for /f ... in ('netstat -ano | findstr ":8000" | findstr "LISTENING"')` 在端口空闲时匹配不到任何行，管道最后的 `findstr` 返回 1；紧随其后的 `start` 不重置 `errorlevel`，于是 `if errorlevel 1 goto :fail` 误判为启动失败。

规避：调用 `start` 之前显式清一次错误码，例如：

```bat
ver >nul
start "Title" /D "%ROOT%" "%ComSpec%" /k "command"
if errorlevel 1 goto :fail
```

更一般地，凡是 `for /f` + `findstr` 探测之后紧接着用 `if errorlevel` 判断别的命令，都要先重置错误码。

### 在 Git Bash 里验证 findstr 会得到假失败（实测）

现象：在 Git Bash 中执行 `netstat -ano | findstr /R /C:"LISTENING" | findstr /C:":8000 "` 报
`FINDSTR: cannot open C:LISTENING`（或中文 `无法打开 C:LISTENING`），看起来像脚本里的端口探测写错了。

原因：MSYS/MinGW 会把形如 `/R`、`/C:` 的参数当成 Unix 路径做自动转换，`/C:"LISTENING"` 被改写成 `C:LISTENING`。
这是 Git Bash 的假象，`.bat` 在真实 `cmd.exe` 里执行时不会有这个问题。

规避：在 Git Bash 里做这类验证时先 `export MSYS_NO_PATHCONV=1`，或改用 `MSYS2_ARG_CONV_EXCL='*'`。
不要因为看到这条报错就去"修"脚本里本来正确的 findstr 写法。

### 无法执行 .bat 时的降级验证路径

当运行环境禁止调用 `cmd.exe`（安全策略拦截）时，不要凭猜测宣称脚本可用，改为：
1. 字节级检查：纯 ASCII、CRLF、无裸 LF/CR、无控制字符（`file start.bat` 应报 `ASCII text, with CRLF line terminators`）；
2. 静态检查：`goto` 目标与标签一一对应、关键步骤都有 `errorlevel` 检查、成功/失败出口齐全、没有真正执行杀进程或清端口的命令；
3. 逐条验证脚本内部用到的真实命令语义：依赖导入的退出码、配置读取的单行表达式输出、`netstat` + `findstr` 取 PID、`curl -f` 在服务未起/已起时的退出码；
4. 用同一批命令模拟各分支（端口被占、端口空闲后启动、服务已在运行），确认判定结果符合脚本里的 `goto` 走向；
5. 报告中明确标注这是降级验证，并点出未能实测的片段（例如 `start` 弹窗行为）。
