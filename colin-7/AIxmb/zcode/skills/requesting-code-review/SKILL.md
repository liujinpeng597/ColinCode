---
name: requesting-code-review
description: Perform a read-only, findings-first review of code changes against requirements, tests, and engineering risk. Use after implementing meaningful changes, at a review checkpoint, before merge or handoff, or when the user explicitly asks to review code, files, commits, or diffs.
---

# Requesting Code Review

## Review Contract

Treat review as read-only by default. A request to review code does not authorize editing files, resolving findings, committing, or pushing changes.

When review is part of an already-authorized implementation task, fixes within that task's original scope may follow the review. When the user requested only a review, report findings and wait for explicit authorization before modifying code.

Lead with concrete findings grounded in inspected code. Read `code-reviewer.md` completely before reviewing or dispatching a reviewer; use it as the canonical checklist, severity scale, output format, and verdict definition.

## Review Mode

Prefer an independent reviewer when the environment provides one and the change is meaningful or risky. Keep delegation to one level:

- The implementing agent may dispatch one reviewer.
- A dispatched reviewer must review directly and must not delegate the same review again.
- For tiny, low-risk changes or when no independent reviewer is available, review inline.

Give the reviewer requirements and raw work artifacts, not a transcript of the implementer's reasoning or expected findings.

## Collect Context

Collect the smallest complete context needed:

- What changed and why.
- Requirements, plan, ticket, task text, or explicit acceptance criteria.
- Known deviations and intentional non-goals.
- Tests run, exact commands, outcomes, and skipped checks with reasons.
- Security, data, compatibility, dependency, migration, rollout, and rollback risks that apply.

Do not require commits. Use the best available source and verify the actual final state.

## Establish Review Scope

For a Git repository, start with `git status --short` to identify staged, unstaged, and untracked work. This command does not show commits already made on the current branch, so separately establish the requested base, range, or upstream comparison before concluding that there are no changes.

Select and combine sources as needed:

| Situation | Review source |
|-----------|---------------|
| Branch or PR compared with its base | `git diff BASE...HEAD` to compare from the merge base |
| Known linear range where BASE is an ancestor of HEAD | `git diff BASE..HEAD` |
| Staged changes | `git diff --staged` |
| Unstaged changes | `git diff` |
| Mixed staged and unstaged changes | Review both layered diffs, then `git diff HEAD` and the final files |
| Untracked files | List with `git ls-files --others --exclude-standard`, then inspect relevant file contents |
| Explicit files requested | Read those files and relevant surrounding code |
| No Git repository | Read the provided files and relevant surrounding code |

When no base or range is supplied for committed work, inspect branch and upstream metadata or commit history to identify the likely comparison. Do not silently guess a base when different choices would materially change the review scope; state the assumption or ask the user when necessary.

When reviewing a commit range, also account for relevant staged, unstaged, and untracked work unless the requested scope explicitly excludes it.

Do not stop at the diff when behavior depends on surrounding code. Inspect affected callers, public interfaces, types, configuration, data models, migrations, dependencies, and tests in proportion to risk.

Keep unrelated user changes out of scope. If they overlap the requested work, separate the relevant hunks where possible and state any remaining uncertainty.

## Verify Behavior

Run safe, relevant, non-destructive tests and static checks when the task and environment authorize local verification. Prefer focused checks first, then broaden them according to the change's risk and blast radius.

Do not claim a check passed without command output or equivalent evidence. If a check cannot be run, continue the review where possible and record the reason, affected confidence, and residual risk.

## Handle Incomplete Context

Continue with a clearly labeled limited review when requirements are ambiguous, tests are missing, or security, migration, or destructive-operation context is incomplete. Treat missing context as an open question, test gap, finding, or residual risk according to its impact.

Stop and ask the user only when:

- The review target or requested scope cannot be identified.
- Relevant and unrelated user changes cannot be separated well enough to make accurate claims.
- Required access or artifacts are unavailable and no meaningful review can proceed safely.

When stopping, report any findings already established, what is missing, and why it prevents a reliable verdict.

## Act on Findings

For a standalone review, report findings without modifying files.

For an authorized implementation task:

- Resolve P0 and P1 findings within the original task scope before handoff unless the user explicitly accepts the risk.
- Triage P2 findings based on scope and timing; repeated P2 findings may indicate a broader design problem.
- Treat P3 findings as optional cleanup.
- Re-review changed areas and affected tests after fixes.
- Challenge incorrect feedback with requirements, code, or test evidence.
