---
name: writing-plans
description: Use when the user explicitly invokes `/writing-plans` or explicitly asks to use the writing-plans skill to turn an approved product, system, UX, or interface design into an implementation-ready plan
---

# Writing Plans

## Overview

Turn an approved spec or concrete requirements into an implementation plan that another capable engineer can execute without guessing. The plan should make scope, files, task order, tests, risks, boundaries, dependencies, and verification explicit.

**Manual trigger only:** Do not use this skill unless the user explicitly invokes `/writing-plans` or explicitly asks to use the writing-plans skill by name.

<MANUAL-TRIGGER>
This skill does not apply automatically merely because a request contains a spec, design, concrete requirements, or a multi-step implementation task. If the user did not explicitly invoke or name this skill, continue with the normal workflow for the request.
</MANUAL-TRIGGER>

**Announce at start:** In the user's current language, state that you are using the writing-plans skill to create the implementation plan.

Do not touch implementation code while writing the plan unless the user explicitly asks to skip planning and start implementation.

## Core Principles

- **Executable over impressive:** Every task should tell the implementer what to change, where, how to verify it, and what outcome to expect.
- **Scale the plan to the work:** Use a single plan file for small and medium work. Use phased plan directories only for large or risky work.
- **Default to no commits:** Do not include commit steps unless the user explicitly requested commits.
- **TDD where practical:** Prefer test-first tasks for behavior changes. If test-first is not practical, explain why and include another verification path.
- **DRY and YAGNI:** Avoid repeated boilerplate and unrequested architecture.
- **No hidden assumptions:** Make security, boundaries, dependencies, runtime assumptions, blocking questions, and deferred decisions visible.
- **Preserve approved design intent:** For user-facing work, carry the spec's interface design contract into files, tasks, implementation details, and visual acceptance checks. Do not silently replace it with generic UI conventions.

## Scope Check

Before writing tasks, compare the request or spec against the intended plan:

- If the spec covers multiple independent subsystems, recommend splitting it into separate plans before continuing.
- If a requirement is ambiguous enough to change the implementation, ask for clarification before planning that part.
- If the user asks to proceed despite ambiguity, mark the assumption explicitly in the plan.
- If the task is small enough for one coherent implementation pass, use the single-file format.
- If the task has multiple natural review points, infrastructure plus feature work, migrations, or risky dependencies, use the phased format.

## Explore Project Context

Before mapping files or writing tasks, inspect enough of the current project to ground the plan in reality:

- Read the relevant project instructions, docs, specs, and architecture notes.
- Inspect the existing source files, tests, configuration, and nearby implementations related to the requested change.
- Discover the project's real build, test, lint, formatting, migration, and verification commands from project files when available.
- Check repository conventions and relevant recent changes when version-control history is available. If the directory is not under version control or has no useful history, rely on the available files and documentation.
- Record any context that cannot be discovered as a blocking question or a deferred decision with a safe default; do not invent paths, commands, interfaces, or dependencies.
- For user-facing work, inspect existing routes, layouts, components, styles, tokens, fonts, icon libraries, assets, responsive rules, test tooling, and screenshot or browser-verification setup.
- If the source spec contains an interface design contract, treat approved decisions as requirements. If it does not, extract any UI decisions present in the conversation or requirements and identify only implementation-blocking gaps.

## Interface Design Traceability

Apply this section only when the plan creates or materially changes a user-facing interface.

Before writing tasks, build a compact mapping from approved design intent to implementation work:

| Design Decision | Source | Implementation Surface | Verification |
|-----------------|--------|------------------------|--------------|
| Primary journey or screen | Spec section | Route, page, state, or flow | Interaction test or manual flow |
| Layout and responsive rule | Interface contract | Layout/component/style files | Named viewport checks |
| Token or visual-system decision | Interface contract or existing system | Theme, CSS variables, tokens, fonts | Computed style or screenshot review |
| Component and interaction state | Interface contract | Component and state logic | Focused state/interaction coverage |
| Content and feedback message | Interface contract | UI copy, validation, empty/error state | Assertion or manual check |
| Accessibility requirement | Interface contract | Semantics, focus, keyboard, motion | Automated and manual accessibility checks |
| Signature element or asset | Interface contract | Asset and rendering implementation | Screenshot and behavior check |

Use the mapping to create actual tasks; do not leave it as documentation only. Every approved design decision must map to at least one file/task and one verification method, or be marked as an explicit non-goal or deferred decision with a safe default.

When the project already has a design system, plan extensions through its established tokens and components. When no system exists, define only the smallest reusable token and component layer required by the approved interface. Do not create a broad design system as incidental scope.

## Plan Format Decision

| Situation | Format |
|-----------|--------|
| One coherent change, few natural review points, and low migration or rollout risk | Single plan file |
| Multiple natural review points, migrations, broad surface area, risky dependencies, or staged rollout | Phased plan directory |
| Multiple independent subsystems | Split into separate plans |

Task count is a heuristic, not a hard boundary. Prefer the structure that makes implementation, verification, review, and rollback clearest without creating unnecessary files.

## File and Boundary Mapping

Before defining tasks, map the files and units involved. This locks in decomposition decisions early.

- List files to create, modify, or test with exact paths when known.
- State each file or module's responsibility.
- Define public interfaces, ownership boundaries, and what each unit must not own.
- Identify internal modules, external services, libraries, data sources, configuration, runtime assumptions, and secrets.
- In existing codebases, follow established patterns unless there is a concrete reason to diverge.
- Include focused cleanup only when it directly supports the planned work.

## Task Granularity

Each task should be small enough to implement, verify, and review independently. A good task usually has:

- A clear goal.
- Exact files or modules involved.
- Concrete implementation steps.
- Tests or verification commands with expected results.
- Notes for security, dependencies, migrations, or rollback when relevant.
- For UI tasks, the exact approved design decisions being implemented and the states and viewport sizes used to verify them.

Avoid mechanical micro-steps that add noise. "Write failing test", "implement behavior", and "run focused test" are useful when they clarify TDD flow; they do not need to be forced into every task.

## Status Maintenance

Plan status fields are working-state markers for future execution, not decoration.

- Use `Not Started` when the plan, phase, or task has not begun.
- Use `In Progress` when implementation work has started but required verification is not complete.
- Use `Blocked` when progress depends on a user decision, missing dependency, unavailable service, failing environment, unresolved blocking question, or required verification that cannot currently run. Document the exact blocker and what will unblock it.
- Use `Done` only after the planned work is implemented and all required verification steps have passed.
- When executing from a plan, update the top-level status, phase status, and completed task checkboxes as work progresses.
- Keep status changes synchronized: a phase should not be `Done` while any required task or phase completion checklist item remains incomplete.
- If the implemented scope changes, update the plan tasks, assumptions, verification, and rollback notes instead of only changing the status.

## Code and Command Detail

Plans must be specific enough to build from, but they should not copy huge files into the plan.

- Include exact test code, interfaces, schemas, command lines, and complex logic when they are central to the task.
- For simple mechanical edits, describe the exact change and target location instead of pasting whole files.
- Do not write vague instructions such as "add validation" or "handle edge cases" without specifying what validation or which edge cases.
- Use current project commands when discoverable. If an unknown command is required for implementation or verification, treat it as a blocking question. If it is optional and a safe fallback exists, record it as a deferred decision together with that fallback.
- Include expected command outcomes: pass, fail-first message, generated file, migration result, or manual verification observation.

## Single-File Plan Format

Use this for small and medium tasks.

**File:** Prefer the project's existing plan/docs location. If none exists, use `docs/plans/YYYY-MM-DD-<feature-name>.md`.

```markdown
# [Feature Name] Implementation Plan

**Created:** YYYY-MM-DD
**Status:** Not Started
**Source Spec:** [path or "inline requirements from conversation"]

## Overview

**Goal:** [One sentence describing what this builds]

**Approach:** [2-3 sentences about the implementation strategy]

**Tech Stack:** [Relevant frameworks, libraries, runtimes, services]

## Files and Responsibilities

| File/Module | Action | Responsibility | Notes |
|-------------|--------|----------------|-------|
| `path/to/file` | Create/Modify/Test | [what it owns] | [interfaces, constraints, dependencies] |

## Interface Implementation Map

Include only for user-facing work. Map each approved journey, layout rule, visual token, component state, content requirement, accessibility rule, and signature element to concrete files/tasks and verification.

## Assumptions and Dependencies

- [Runtime, service, library, data, config, or sequencing assumption]

## Tasks

### Task 1: [Name]

**Goal:** [What this task accomplishes]

**Files:**
- Create/Modify/Test: `exact/path`

**Steps:**
- [ ] [Concrete step]
- [ ] [Concrete step]
- [ ] Run: `command`
  - Expected: [specific pass/fail/observable result]

**Security/Boundary Notes:** [Only if relevant]

---

### Task 2: [Name]

[Repeat only as needed]

## Verification

- [ ] [Focused tests]
- [ ] [Integration or manual checks]
- [ ] [Regression checks]
- [ ] [For UI work: representative mobile and desktop viewport checks]
- [ ] [For UI work: keyboard, focus, loading, empty, error, and reduced-motion states as applicable]
- [ ] [For UI work: screenshot or browser review against the approved interface design contract]

## Rollback

- [How to disable, revert, migrate back, or recover if relevant]

## Blocking Questions

- [Questions that must be answered before this plan can be handed off as implementation-ready. Resolve all of them, then omit this section from the final plan.]

## Deferred Decisions

- [Non-blocking decision, why it can wait, and the safe default implementation should use until it is resolved]
```

## Phased Plan Format

Use this for large, risky, or multi-stage work. Each phase should produce working, testable software.

**Directory:** Prefer the project's existing plan/docs location. If none exists, use `docs/plans/YYYY-MM-DD-<feature-name>/`.

**Directory structure:**

```text
docs/plans/YYYY-MM-DD-<feature-name>/
├── <feature-name>.md
├── phase-1-<name>.md
├── phase-2-<name>.md
└── phase-N-<name>.md
```

**Phase constraints:**

- Keep each phase focused enough to implement, verify, and review as one coherent unit. Two to five tasks is a useful default, not a hard limit.
- Phases build sequentially.
- Each phase has its own verification and rollback notes when relevant.
- Create natural review points between phases.

### Index File

**File:** `docs/plans/YYYY-MM-DD-<feature-name>/<feature-name>.md`

```markdown
# [Feature Name] Implementation Plan

**Created:** YYYY-MM-DD
**Status:** Not Started
**Source Spec:** [path or "inline requirements from conversation"]

## Overview

**Goal:** [One sentence describing what this builds]

**Architecture:** [2-3 sentences about approach]

**Tech Stack:** [Key technologies/libraries]

## Files and Responsibilities

| File/Module | Action | Responsibility | Notes |
|-------------|--------|----------------|-------|
| `path/to/file` | Create/Modify/Test | [what it owns] | [interfaces, constraints, dependencies] |

## Interface Implementation Map

Include only for user-facing work. Map approved interface decisions to phases, files, states, assets, and visual verification targets.

## Phases

### Phase 1: [Phase Name]
**File:** [phase-1-<name>.md](phase-1-<name>.md)
**Goal:** [What this phase achieves]
**Tasks:** N
**Status:** Not Started

### Phase 2: [Phase Name]
**File:** [phase-2-<name>.md](phase-2-<name>.md)
**Goal:** [What this phase achieves]
**Tasks:** N
**Status:** Not Started

## Dependencies

- [Phase sequencing, external services, libraries, data, config, or runtime assumptions]

## Success Criteria

- [ ] [Feature-specific behavior works]
- [ ] Tests pass
- [ ] Documentation updated if needed
- [ ] Security, boundary, and dependency assumptions verified

## Blocking Questions

- [Questions that must be answered before this plan can be handed off as implementation-ready. Resolve all of them, then omit this section from the final plan.]

## Deferred Decisions

- [Non-blocking decision, why it can wait, and the safe default implementation should use until it is resolved]
```

### Phase File

**File:** `docs/plans/YYYY-MM-DD-<feature-name>/phase-N-<name>.md`

```markdown
# Phase N: [Phase Name]

**Goal:** [What this phase achieves]
**Prerequisites:** [What must be done before this phase]
**Deliverables:** [What this phase produces]

**Interface Decisions Implemented:** [For UI phases, list the approved journeys, layout rules, tokens, components, states, responsive behavior, accessibility requirements, or signature elements completed here]

---

## Task 1: [Name]

**Goal:** [What this task accomplishes]

**Files:**
- Create: `exact/path/to/file.ext`
- Modify: `exact/path/to/existing.ext`
- Test: `tests/exact/path/to/test.ext`

**Steps:**
- [ ] Write or update the focused test.

```language
[specific test code when useful]
```

- [ ] Run: `command to run focused test`
  - Expected: [specific fail-first or pass result]

- [ ] Implement the minimal behavior.

```language
[specific interface, schema, or core logic when useful]
```

- [ ] Run: `command to verify`
  - Expected: [specific result]

**Security/Boundary Notes:** [Only if relevant]

**Dependencies:** [Only if relevant]

**Visual Verification:** [For UI tasks, list representative routes/states, viewport sizes, interactions, screenshots, and expected observable results]

---

## Phase Completion Checklist

- [ ] All tasks completed
- [ ] Focused tests passing
- [ ] Relevant broader tests passing
- [ ] Documentation updated if needed
- [ ] Ready for next phase
```

## No Placeholders

These are plan failures. Do not leave them in the final plan:

- `TBD`, `TODO`, `implement later`, `fill in details`
- "Add appropriate error handling" without naming the errors and responses
- "Add validation" without listing fields, constraints, and failure behavior
- "Handle edge cases" without naming the edge cases
- "Write tests" without naming the cases or showing important test code
- "Match the design", "make it polished", or "make it responsive" without naming the relevant contract decisions, breakpoints or viewport checks, states, and observable acceptance criteria
- References to types, functions, files, commands, or services that are neither defined nor discoverable and have not been resolved as blocking questions or documented as deferred decisions with safe defaults
- Commit steps unless the user explicitly requested commits

## Self-Review

After writing the complete plan, review it with fresh eyes and fix issues inline.

1. **Spec coverage:** Every requirement in the spec maps to at least one task, verification step, or explicit non-goal.
2. **Placeholder scan:** Remove all red flags from the "No Placeholders" section.
3. **Type and naming consistency:** Types, functions, routes, files, commands, and property names match across tasks.
4. **Task buildability:** Each task has enough file paths, steps, and verification detail for implementation without guessing.
5. **Phase balance:** Single-file plans stay coherent; phased plans use natural implementation and review boundaries, and each phase is testable without enforcing an arbitrary task-count limit.
6. **Security check:** Plan covers relevant trust boundaries, authorization, sensitive data, input validation, secret handling, and abuse cases, or states why they are not relevant.
7. **Boundary check:** File/module responsibilities, public interfaces, ownership boundaries, and handoffs are explicit.
8. **Dependency check:** Internal/external dependencies, runtime assumptions, configuration, data sources, sequencing, and unresolved dependency choices are explicit. Blocking questions are resolved before handoff, and every deferred decision includes a safe default.
9. **Testing risk check:** Test coverage matches the risk of the change. Critical behavior has focused tests and relevant regression coverage.
10. **Migration and rollback check:** Data migrations, compatibility, rollout, disablement, and recovery steps are addressed when relevant.
11. **Interface traceability check:** For user-facing work, every approved journey, layout rule, token, component state, content requirement, responsive behavior, accessibility requirement, asset, and signature element maps to implementation work and verification. Ensure the plan does not substitute a new aesthetic direction.
12. **Visual verification check:** Name representative routes, data states, viewport sizes, interaction states, screenshot expectations, and browser or accessibility checks. Include a post-implementation critique pass that fixes visible hierarchy, spacing, overflow, overlap, contrast, and fidelity issues before completion.
13. **Command check:** Verification commands are real project commands when discoverable. Any required unknown command is resolved as a blocking question; an optional unknown command may be deferred only with a safe fallback.

If you find issues, fix them inline. If a spec requirement has no task, add the task. If the plan depends on an unanswered decision, classify it as blocking or deferred. Resolve every blocking question before handoff; for each deferred decision, document why it is non-blocking and which safe default implementation should use.

## Optional Plan Reviewer

Look for `plan-document-reviewer-prompt.md` in the skill directory first. If it is available, use it only as a local self-review checklist after the plan is written and self-reviewed; do not delegate the review.

The reviewer is advisory unless it finds material issues that would cause implementation to fail, drift from the spec, cross unclear boundaries, rely on unstated dependencies, miss required verification, or violate user instructions such as commit policy. If the reviewer finds material issues, fix them inline and re-check the affected sections before handoff.

## Execution Handoff and Stop Conditions

After the plan is complete, contains no unresolved blocking questions, and has been saved, stop and hand it to the user:

> "Plan complete and saved to `<path>`. Please review it and tell me if you want changes or want me to start implementation."

Do not start implementation automatically. Wait for the user to review the written plan and explicitly request the next action.

If the user explicitly asks to implement after the plan:

- Proceed according to the current session's normal execution workflow.
- Use any relevant execution or review skills only if they are actually available in this environment.
- Do not create commits unless the user explicitly asks.

If the user does not review or does not respond, leave the plan as the handoff artifact and remain stopped.

If the user asks to skip planning and directly implement, exit this skill and follow the user's explicit implementation request.
