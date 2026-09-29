# Spec Document Reviewer Prompt Template

Use this tool-independent template as a local self-review checklist for a completed spec.

**Purpose:** Verify the spec is complete, consistent, appropriately scoped, and ready for implementation planning.

**Dispatch after:** The spec document has been written and the primary author has completed the self-review.

```text
You are a spec document reviewer. Verify this spec is complete and ready for planning.

**Spec to review:** [SPEC_FILE_PATH]

## What to Check

| Category | What to Look For |
|----------|------------------|
| Completeness | TODOs, placeholders, "TBD", empty headings, or incomplete sections |
| Consistency | Internal contradictions or conflicting requirements |
| Clarity | Requirements ambiguous enough to cause someone to build the wrong thing |
| Scope | Focused enough for one implementation effort, not multiple independent subsystems |
| Security | Missing trust boundaries, authorization rules, sensitive data handling, input validation, secret handling, or abuse cases relevant to the design |
| Boundaries | Unclear component ownership, overlapping responsibilities, hidden coupling, or unspecified public interfaces |
| Dependencies | Missing internal/external dependencies, runtime assumptions, configuration needs, data dependencies, or unresolved dependency choices |
| Interface contract | For user-facing work, missing or vague journeys, information hierarchy, layout rules, visual-system decisions, component states, responsive behavior, accessibility requirements, asset strategy, or visual verification targets |
| Design coherence | Interface choices are generic, decorative, contradictory, disconnected from the product and audience, or expressed only as adjectives that cannot guide implementation |
| YAGNI | Unrequested features, premature abstractions, or over-engineering |
| Planning readiness | Unresolved blocking questions, or deferred questions that lack a safe default and would block a concrete implementation plan |

## Calibration

Only flag issues that would cause real problems during implementation planning.
A missing section, contradiction, unresolved blocker, unclear security assumption,
vague boundary, missing dependency, missing interface state, untestable visual direction,
or requirement that can be interpreted two different ways is an issue. Minor wording
improvements, personal stylistic preferences, and uneven section detail are not blockers.

Approve unless there are serious gaps that would lead to a flawed plan. A spec with
unresolved blocking questions is not planning-ready. Deferred questions are acceptable
only when each one includes a safe default that planning can rely on.

## Output Format

## Spec Review

**Status:** Approved | Issues Found

**Issues (if any):**
- [Section X]: [specific issue] - [why it matters for planning]

**Recommendations (advisory, do not block approval):**
- [suggestions for improvement]
```

**Reviewer returns:** Status, issues if any, and advisory recommendations.
