---
name: verification-loop
description: Use after code changes, before handoff, before review, or before merge to verify build, tests, risks, and changed files
---

# Verification Loop

## Overview

Verify code changes with project-appropriate commands and evidence before handoff. The loop should prove what was checked, what failed, what was skipped, and what residual risk remains.

**Core principle:** Verification is evidence, not vibes. Report commands, outcomes, and unresolved risk.

Do not claim work is complete, fixed, passing, ready, or safe until fresh verification evidence supports that exact claim.

## When to Use

Use this:

- After completing a feature, bug fix, refactor, or planned task.
- Before requesting code review.
- Before handing work back to the user.
- Before merge or release.
- After touching security, data, migrations, dependencies, cross-module behavior, or external integrations.
- When a previous verification failed and was fixed.

Use this especially before any status message that implies success or completion.

## Completion Claim Gate

Before making any success claim:

1. **Identify:** What command, checklist, diff, or inspection proves this claim?
2. **Run or inspect fresh evidence:** Use current workspace state, not memory or an earlier run.
3. **Read the output:** Check exit code, failures, warnings, skipped tests, and relevant summary.
4. **Compare to the claim:** Does the evidence prove the exact statement?
5. **State the result with evidence:** If not proven, state the actual status and residual risk.

Common claims and required evidence:

| Claim | Requires | Not Enough |
|-------|----------|------------|
| Tests pass | Current test command output with zero relevant failures | "Should pass", previous run |
| Build succeeds | Current build/compile command exit 0 | Lint passing |
| Bug fixed | Original reproduction or regression test now passes | Code changed |
| Regression test works | Valid RED/GREEN evidence when practical | Test passes once without RED |
| Requirements met | Requirements/plan checklist mapped to completed work | Tests passing alone |
| Ready for review/merge | Verification report, diff review, and residual risk summary | Agent/tool says success |

Avoid success wording such as "done", "fixed", "complete", "ready", or "all good" unless the evidence is fresh and specific.

## Phase 0: Discover Project Verification Commands

Before running checks, inspect the project enough to avoid invented commands:

- Package/build files: `package.json`, `pnpm-workspace.yaml`, `pyproject.toml`, `tox.ini`, `go.mod`, `Cargo.toml`, `pom.xml`, `build.gradle`, `.sln`, `Makefile`, `justfile`.
- CI files: `.github/workflows/*`, `.gitlab-ci.yml`, `azure-pipelines.yml`, `Jenkinsfile`.
- Existing scripts for build, test, typecheck, lint, format, coverage, E2E, security, migration, and docs.
- Monorepo/workspace scope and which package was touched.
- Existing coverage thresholds, if configured.

Use discovered project commands. If a command cannot be found, mark it as unknown instead of inventing one.

## Verification Scope

Choose the lightest scope that matches the risk.

| Scope | Use When | Typical Checks |
|-------|----------|----------------|
| Focused | Small localized change | Targeted test, relevant type/lint/build check |
| Standard | Normal feature or bug fix | Focused tests, broader regression tests, typecheck/lint/build, diff review |
| Full | High-risk or release-bound change | Standard checks plus E2E, coverage, migration/rollback, security/dependency scans |

High-risk changes include auth, permissions, payments, secrets, data migrations, destructive file operations, concurrency, external integrations, generated artifacts, public APIs, and cross-package behavior.

## Core Verification Phases

Run the phases that apply to the chosen scope. Record skipped phases with reasons.

### 1. Build / Compile

Run the project build or compile command when available.

Examples:

```bash
npm run build
pnpm build
python -m compileall .
go test ./...
cargo test
mvn test
dotnet build
```

If build or compile fails because of the current change, stop and fix it before continuing. If it fails for a known unrelated reason, record the evidence and residual risk.

### 2. Type Check / Static Analysis

Run project type or static checks when available.

Examples:

```bash
npm run typecheck
npx tsc --noEmit
pyright .
mypy .
cargo check
go vet ./...
```

Report errors with enough detail to act on them.

### 3. Lint / Format Check

Run lint or format checks when available.

Examples:

```bash
npm run lint
pnpm lint
ruff check .
black --check .
cargo fmt --check
gofmt -w
```

Prefer check-only commands for verification. Do not run formatters that modify files unless that is part of the requested work.

### 4. Tests

Run tests according to risk:

- Focused tests for touched behavior.
- Regression tests for the affected package/module.
- Integration or E2E tests for cross-boundary or user-flow changes.
- Coverage only when the project has a configured threshold or the risk justifies it.

Coverage policy:

- Follow existing project thresholds when configured.
- Do not impose a universal 80% threshold.
- If coverage cannot be measured, report that instead of guessing.

For TDD work, include RED/GREEN evidence if available: focused RED command/result, focused GREEN command/result, and any broader checks.

### 5. Security and Secrets

Prefer project security tools if present:

```bash
npm audit
pnpm audit
pip-audit
cargo audit
gitleaks detect
trufflehog filesystem .
```

If no tool exists, perform a lightweight targeted review instead of pretending grep is comprehensive:

- Search changed files for hardcoded secrets, tokens, credentials, private keys, and unsafe defaults.
- Check logs and errors for sensitive data exposure.
- Check input validation, output encoding, authz/authn, injection risks, and abuse cases for touched behavior.
- Review config and environment variable handling.

Do not treat `console.log` as automatically a security issue. Treat it as a risk only if it leaks data, violates project logging policy, or is debug residue in production code.

### 6. Boundaries and Dependencies

Review whether the change respects design boundaries:

- File/module responsibilities remain clear.
- Public interfaces and ownership boundaries are preserved.
- No hidden coupling or responsibility drift was introduced.
- External services, runtime assumptions, config, environment variables, data sources, and versions are explicit.
- Mocks/fakes in tests preserve required behavior contracts.

### 7. Migration, Rollback, and Compatibility

Run or review these when relevant:

- Database migration checks or dry runs.
- Backward/forward compatibility.
- Data migration safety and idempotency.
- Feature flag, disablement, or rollback path.
- Generated artifact consistency.
- API compatibility for consumers.

### 8. Diff Review

Review the actual changed files.

Use the best available source:

```bash
git diff --stat
git diff
git diff --staged
git diff BASE..HEAD
```

If there is no git repository, review the changed or requested files directly.

Check for:

- Unintended files or unrelated changes.
- Debug residue.
- Missing tests/docs.
- Missing error handling.
- Risky file operations or destructive commands.
- Security, boundary, dependency, migration, or rollback gaps.

## Failure Handling

Classify failures:

- **Blocking:** Caused by the current change and prevents safe handoff. Fix before proceeding.
- **Known unrelated:** Existing failure outside the current change. Record evidence and residual risk.
- **Unknown:** Cannot determine cause. Investigate enough to classify or ask the user.
- **Skipped:** Command unavailable, too expensive, destructive, or out of scope. Record why and what risk remains.

Do not hide failures. A verification report with known failures is acceptable only if the risk is explicit.

## Output Report

Use this report format:

```markdown
## Verification Report

**Scope:** Focused | Standard | Full
**Verdict:** Ready | Ready with residual risk | Not ready | Blocked

## Completion Claim Evidence

- Claim: [what you are claiming]
- Evidence: [fresh command/checklist/diff/inspection that proves it]
- Not verified: [anything the claim does not cover]

## Commands

| Phase | Command | Result | Notes |
|-------|---------|--------|-------|
| Build | `command` | PASS/FAIL/SKIPPED | Key output or reason |
| Types | `command` | PASS/FAIL/SKIPPED | Key output or reason |
| Lint | `command` | PASS/FAIL/SKIPPED | Key output or reason |
| Tests | `command` | PASS/FAIL/SKIPPED | X passed, Y failed, relevant summary |
| Security | `command or review` | PASS/FAIL/SKIPPED | Findings or reason |

## Diff Reviewed

- Source: `git diff`, `git diff --staged`, `BASE..HEAD`, file list, or no-git review
- Files reviewed: N
- Notable changes: [brief summary]

## Risk Checks

- Security: PASS/ISSUES/SKIPPED - [summary]
- Boundaries: PASS/ISSUES/SKIPPED - [summary]
- Dependencies: PASS/ISSUES/SKIPPED - [summary]
- Migration/Rollback: PASS/ISSUES/SKIPPED - [summary]

## Requirements Check

- [ ] [Requirement or plan item] - Verified by [command/check/file]

## Issues

1. [Blocking or important issue, file/line if available]

## Residual Risk

- [Anything not verified, skipped, flaky, or uncertain]
```

If everything passed and no residual risk remains, say so clearly. If anything was skipped, include the reason.

## Integration with Other Skills

- After `test-driven-development`, include valid RED/GREEN evidence and broader regression checks.
- After `writing-plans`, verify against the plan's success criteria and tasks.
- Before `requesting-code-review`, use the verification report as the review input's tests/risks section.

## Stop Conditions

Stop and ask the user before claiming ready when:

- A blocking verification command fails.
- Fresh evidence does not support the completion claim you are about to make.
- The project command cannot be discovered for a high-risk change.
- Security, migration, destructive operation, or data-loss risk cannot be verified.
- Tests are unavailable for a behavior change and no substitute verification is acceptable.
- Diff contains unrelated user changes that cannot be separated safely.

If stopped, report what is missing, why it matters, and the safest next step.
