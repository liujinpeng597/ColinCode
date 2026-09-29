---
name: systematic-debugging
description: Use when encountering any bug, test failure, build failure, performance problem, integration issue, or unexpected behavior before proposing fixes
---

# Systematic Debugging

## Overview

Debug by evidence. Reproduce the symptom, trace the cause, form one hypothesis, test it minimally, then fix the root cause.

**Core principle:** Do not guess fixes. Understand why the issue happens before changing production behavior.

## When to Use

Use for:

- Test failures
- Production bugs
- Unexpected behavior
- Performance regressions
- Build/type/lint failures
- Integration failures
- Flaky tests
- Data, environment, dependency, or configuration problems

Use especially when:

- A quick fix seems obvious.
- You already tried a fix and it failed.
- Multiple components are involved.
- The issue appears only in CI or only on one machine.
- You do not fully understand the failure.

## Incident Mitigation

If users, data, security, or production availability are at immediate risk, mitigation may come before full root cause analysis.

Allowed mitigation:

- Roll back.
- Disable a feature flag.
- Stop a destructive job.
- Rotate or revoke exposed credentials.
- Block unsafe input.
- Preserve logs, artifacts, and affected data for later analysis.

Mitigation is not the root cause fix. After containment, continue the systematic debugging flow and document what was mitigated.

## Debugging Flow

Complete each phase in order unless an incident mitigation is required.

### Phase 1: Observe and Reproduce

Gather facts before proposing fixes.

1. **Read the error carefully**
   - Full error message, stack trace, status code, logs, and line numbers.
   - Distinguish primary failure from follow-on noise.

2. **Reproduce consistently**
   - Exact command, input, environment, and steps.
   - Expected behavior vs actual behavior.
   - Whether it happens every time, intermittently, locally, in CI, or only in production.

3. **Discover project and environment context**
   - Relevant scripts and commands.
   - Runtime versions, OS/platform, package manager, dependency versions.
   - Environment variables, config files, secrets presence, feature flags.
   - Monorepo package/workspace boundaries.

4. **Check recent changes**
   - Current diff, staged/unstaged changes, recent commits if available.
   - Dependency, config, data, schema, environment, or infrastructure changes.
   - User changes that must not be overwritten.

5. **Record initial evidence**
   Use the evidence log template below.

### Phase 2: Trace and Localize

Find where the behavior diverges from expectation.

- Trace data flow backward from the symptom to the source.
- Add temporary diagnostic instrumentation at component boundaries when needed.
- Compare local vs CI, old vs new, working vs broken, valid input vs invalid input.
- Identify whether the issue is code, test, data, config, dependency, environment, or architecture.

For deep call-stack bugs, use `root-cause-tracing.md`.

For flaky waits or race conditions, use `condition-based-waiting.md`.

For invalid data crossing multiple layers, use `defense-in-depth.md` after the root cause is known.

### Phase 3: Pattern Analysis

Find the working pattern before fixing.

- Locate similar working code in the same codebase.
- Read relevant framework/library docs or existing implementations when needed.
- List meaningful differences between working and broken paths.
- Identify dependencies and assumptions: external services, config, data shape, runtime, ordering, time, concurrency, permissions, and feature flags.

### Phase 4: Hypothesis Test

Use the scientific method.

1. State one hypothesis:
   - "I think X is the root cause because Y evidence shows Z."
2. Test one variable at a time.
3. Prefer diagnostic changes or focused experiments before production fixes.
4. If the hypothesis fails, record the result and form a new hypothesis.
5. Do not stack speculative fixes.

If three fix attempts fail, stop and question the architecture or the original assumptions before attempting another fix.

### Phase 5: Fix

Fix the root cause, not the symptom.

- For behavior bugs, create a valid RED using `test-driven-development` whenever practical.
- If automated RED is not practical, record why and define the strongest substitute verification.
- Implement the smallest fix that addresses the confirmed root cause.
- Avoid unrelated refactoring and "while here" changes.
- Add defense-in-depth validation only where it protects real boundaries exposed by the root cause.

### Phase 6: Verify and Hand Off

Use `verification-loop` after the fix.

Minimum verification:

- Original reproduction no longer fails.
- Focused regression test passes, if one was added.
- Relevant surrounding tests/checks pass.
- Security, boundary, dependency, migration, and rollback risks are checked when relevant.
- Residual risk is documented.

If the fix is non-trivial or high-risk, use `requesting-code-review` before handoff or merge.

## Evidence Log Template

Use this structure while debugging:

```markdown
## Debugging Evidence

**Symptom:** [What failed]
**Expected:** [What should happen]
**Actual:** [What happened]
**Reproduction:** [Exact command/steps/input]
**Frequency:** Always | Intermittent | CI only | Local only | Production only
**Scope:** [Files, modules, services, users, data affected]

## Context

- Recent changes:
- Environment/runtime:
- Config/secrets/feature flags:
- Dependencies/external services:

## Evidence Collected

1. [Observation, command, output summary]

## Hypotheses

1. Hypothesis: [X because Y]
   - Test: [experiment]
   - Result: [confirmed/rejected/inconclusive]

## Root Cause

[Confirmed root cause and supporting evidence]

## Fix

[What changed and why it addresses the root cause]

## Verification

- [Command/result]

## Residual Risk

- [Unverified areas, skipped checks, external dependencies]
```

## Multi-Component Diagnostics

When multiple layers are involved, add temporary evidence at boundaries:

```text
Client -> API -> Service -> Database
CI -> Build script -> Packaging -> Signing
CLI -> Config loader -> Runtime -> External service
```

For each boundary, capture:

- Input entering the component.
- Output leaving the component.
- Config/environment received.
- Error or state transition.
- Correlation ID, request ID, file path, data ID, or timestamp when useful.

Remove or downgrade temporary diagnostics after the fix unless they are useful production observability and safe for sensitive data.

## Security, Boundaries, and Dependencies

During investigation, explicitly check:

- **Security:** auth/authz, input validation, secret handling, sensitive logs, injection, abuse paths.
- **Boundaries:** which module owns the behavior, public interfaces, hidden coupling, responsibility drift.
- **Dependencies:** external service behavior, versions, config, environment variables, network, filesystem, time, randomness, database state.
- **Data impact:** migrations, corrupt state, compatibility, rollback, and recovery.

## Red Flags

Stop and return to evidence gathering when you catch yourself doing this:

- "Just try changing X."
- "Quick fix now, investigate later" outside incident mitigation.
- "It is probably X" without evidence.
- Multiple speculative changes at once.
- Fixing the line where the error appears without tracing the source.
- Adding retries, sleeps, defaults, or null guards without knowing why the bad state exists.
- Skipping the regression test for a behavior bug.
- Continuing after three failed fixes without questioning assumptions.

## Stop and Escalate

Stop and ask the user before continuing when:

- The issue cannot be reproduced and more data is needed.
- Investigation requires production access, secrets, destructive commands, or external permissions.
- User changes are mixed with your debugging changes and reverting would risk their work.
- Evidence suggests data loss, security exposure, or migration corruption.
- Three fix attempts failed.
- The root cause appears architectural and the fix would change major boundaries.

## Quick Reference

| Phase | Key Question | Output |
|-------|--------------|--------|
| Observe | What exactly failed? | Reproduction and evidence |
| Trace | Where does behavior diverge? | Localized failing boundary |
| Pattern | What does working code do? | Differences and assumptions |
| Hypothesis | What root cause explains evidence? | Confirmed/rejected hypothesis |
| Fix | What smallest change addresses root cause? | Regression test and fix |
| Verify | Did it actually work safely? | Verification report and residual risk |

## Final Rule

```
Evidence -> hypothesis -> minimal test -> root-cause fix -> verification
```

Mitigation may protect users first, but it does not replace root cause analysis.
