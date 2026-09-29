---
name: executing-phased-plans
description: 按顺序执行 writing-plans 生成的多阶段计划。仅在存在阶段索引和独立阶段文件，并且用户明确要求开始实施且授权每阶段创建一个 Git 提交时使用；每阶段派遣一次 tdd-guide，验证后同步任务与索引状态，再由主智能体创建唯一提交。
---

# 执行阶段计划

## 目标

读取 `writing-plans` 生成的阶段索引，依次执行尚未完成的阶段。每个阶段只派遣一个 `tdd-guide`，由它完成代码与测试；主智能体负责验证结果、更新计划状态和创建该阶段唯一的 Git 提交。

不要并行执行阶段。后续阶段可能依赖前一阶段的代码、迁移或验证结果。

## 输入契约

优先使用用户明确提供的索引文件路径。若未提供，只能在当前项目中恰好找到一个符合以下结构的索引时自动选择；存在多个候选时必须询问用户。

阶段索引必须包含：

```markdown
## Phases

### Phase 1: [Phase Name]
**File:** [phase-1-<name>.md](phase-1-<name>.md)
**Goal:** [What this phase achieves]
**Tasks:** N
**Status:** Not Started
```

阶段文件路径必须从 `**File:**` 字段读取，并相对于索引目录解析。不要根据阶段名称猜测路径。

只支持 `writing-plans` 的标题格式。若输入是单文件计划、表格索引、阶段缺少文件链接，或计划仍有未解决的 `Blocking Questions`，停止并说明原因。

## 状态规则

状态字段只使用 `writing-plans` 的标准值：

- `Not Started`
- `In Progress`
- `Blocked`
- `Done`

完成阶段时，在索引中同时写入标准状态和可视标记：

```markdown
**Status:** Done
**Completion:** √
```

判断是否跳过阶段时，以已提交到 `HEAD` 的 `**Status:** Done` 为准；`√` 仅用于展示。工作区里尚未提交的 `Done` 不得视为已完成。

执行期间同步维护：

- 索引顶层 `**Status:**`
- 索引中的阶段 `**Status:**`
- 阶段文件中的任务步骤复选框
- 阶段文件中的 `Phase Completion Checklist`
- 全部阶段结束后的索引 `Success Criteria`

只有存在验证证据的项目才能从 `- [ ]` 改为 `- [x]`。

## 执行流程

### 1. 执行前检查

1. 确认用户已经明确要求开始实施，并授权每阶段创建一个 Git 提交。没有授权时停止，不得自行提交。
2. 确认工作目录是计划所属项目的 Git 仓库根目录。
3. 读取完整索引和所有阶段文件，验证阶段编号、顺序、链接、任务数和前置条件。
4. 检查索引中没有未解决的阻塞问题。
5. 运行 `git status --short`，记录已有的暂存、未暂存和未跟踪文件。
6. 允许 `writing-plans` 刚生成但尚未提交的索引和阶段文件作为输入；记录这些计划文件的路径与内容摘要，并在第一个阶段提交中一并纳入全部计划文件。
7. 若其他已有修改与本阶段 `Files` 中列出的实现或测试文件重叠，将阶段标记为 `Blocked` 并询问用户。不要覆盖、回滚或提交用户已有修改。
8. 使用 `git rev-parse --verify HEAD` 检查仓库是否已有提交。若存在，记录 `BASE_SHA`；若不存在，记录 `INITIAL_REPOSITORY=true`，不要假设新仓库已经有 `HEAD`。

无关的已有修改可以保留，但后续不得暂存或提交这些路径。

### 2. 选择下一阶段

按编号选择第一个尚未在 `HEAD` 中标记为 `Done` 的阶段。

- 开始第一个阶段时，将索引顶层状态改为 `In Progress`。
- 将当前阶段状态改为 `In Progress`，移除遗留的 `**Completion:** √`。
- 检查阶段 `Prerequisites` 已满足，否则标记为 `Blocked` 并停止。

### 3. 派遣 tdd-guide

使用 Agent 工具，参数 subagent_type: tdd-guide。每个阶段只派遣一个 `tdd-guide`，传入完整阶段文件内容，不要只传摘要。

`tdd-guide` 位于 `~/.zcode/agents/tdd-guide.md`。它只负责实现和验证，不得创建 Git 提交、推送、修改计划文件或继续派遣其他子智能体。

提示词模板：

```text
Working directory: <项目 Git 根目录的绝对路径>
Plan index: <索引文件绝对路径>
Phase file: <阶段文件绝对路径>

Execute every task in the phase plan below in order. Load and follow the
test-driven-development skill as the authoritative methodology. Use the
project's actual test and verification commands.

Do not edit the plan index or phase plan files. Do not create Git commits,
push, or dispatch another subagent. Stop on blockers instead of guessing.

Phase plan:
<plan>
{{完整阶段 Markdown 内容}}
</plan>

Report each task's result, RED/GREEN evidence or approved TDD exception,
commands run, test results, changed files, blockers, and remaining risks.
```

### 4. 验证阶段结果

主智能体必须独立检查，不能只依据子智能体的完成声明：

1. 对照阶段文件确认每个任务的交付物和文件范围。
2. 核实有效的 RED/GREEN 证据，或阶段中明确允许的替代验证路径。
3. 运行阶段要求的聚焦测试和相关广泛测试。
4. 检查文档、迁移、回滚和安全边界要求。
5. 运行 `git status --short` 和 `git diff --check`。
6. 确认子智能体没有创建提交：已有 `BASE_SHA` 时，`git rev-list --count "$BASE_SHA..HEAD"` 必须为 `0`；初始仓库中，`HEAD` 仍必须不存在。
7. 确认已有用户修改仍保持原状态，且没有计划外文件被改动。

若验证失败、环境不可用、依赖缺失、范围不明确或子智能体擅自提交：

- 将阶段状态改为 `Blocked`。
- 在计划中记录具体阻塞原因和解除条件。
- 停止当前阶段并向用户报告，不要无限重新派遣，也不要使用破坏性 Git 命令恢复现场。

### 5. 更新计划状态

全部验证通过后：

1. 根据验证证据更新当前阶段的任务步骤复选框。
2. 完成 `Phase Completion Checklist` 中已验证的项目。
3. 将索引中的当前阶段改为：

```markdown
**Status:** Done
**Completion:** √
```

4. 若仍有后续阶段，索引顶层状态保持 `In Progress`。
5. 若全部阶段完成，验证并更新索引 `Success Criteria`，再将顶层状态改为 `Done`。

### 6. 创建唯一的阶段提交

Git 提交只由主智能体创建。

1. 根据阶段 `Files`、实际验证过的新增文件、索引文件和当前阶段文件生成允许暂存的路径集合。若计划目录在执行前尚未提交，第一个阶段还必须包含该目录下全部已审核的计划文件。
2. 逐个暂存允许路径。不得使用会包含无关修改的无边界暂存命令。
3. 使用稳定的提交信息：`phase <N>: <Phase Name>`；若计划明确指定提交信息，则使用计划值。
4. 创建一次提交。
5. 验证：

已有基线提交时验证：

```bash
git rev-list --count "$BASE_SHA..HEAD"
git show --stat --oneline HEAD
git status --short
```

初始仓库中验证：

```bash
git rev-list --count HEAD
git show --stat --oneline HEAD
git status --short
```

预期结果：

- 已有基线时，相对 `BASE_SHA` 恰好新增 `1` 个提交；初始仓库中，提交总数恰好为 `1`。
- 提交包含本阶段实现、测试、当前阶段文件和索引状态更新。
- 没有遗漏的本阶段修改。
- 执行前存在的无关用户修改仍未被提交。

只有上述检查全部通过，才能进入下一阶段。

### 7. 重复并汇总

重复步骤 2 至 6，直到所有阶段完成。最终报告：

- 完成的阶段和任务数
- 每阶段提交 SHA
- 执行的测试和结果
- 保留的用户修改
- 阻塞项或剩余风险

## 中断恢复

恢复执行时同时检查 `HEAD` 和工作区：

- `HEAD` 中阶段状态为 `Done`：跳过该阶段。
- 工作区为 `Done`、但 `HEAD` 不是 `Done`：说明状态更新尚未提交；不要跳过，先核对实现、测试和提交历史。
- 代码已有阶段提交、但索引未完成：标记为 `Blocked`，核对历史后再决定补记、修复或继续。
- 阶段存在未提交的部分实现：在保留现有修改的前提下继续验证，不要为了重新制造 RED 而删除或回滚用户工作。

因此，本流程只有在完成状态已经进入阶段提交后才视为可恢复完成；不要仅凭工作区中的 `√` 宣称幂等。

## 推送策略

不要自动推送。只有用户明确要求推送时，才确认当前分支和远端后执行推送。
