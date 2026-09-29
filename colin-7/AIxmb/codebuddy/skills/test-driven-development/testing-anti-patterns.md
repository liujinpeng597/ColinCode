# Testing Anti-Patterns

**Load this reference when:** writing or changing tests, adding mocks, creating test utilities, or tempted to add test-only methods to production code.

## Overview

Tests must verify real behavior, not incidental mock mechanics. Mocks are tools for isolation; assert their interactions only when the interaction itself is part of the observable contract.

**Core principle:** Test what the system does at a meaningful boundary.

Examples use TypeScript-style syntax, but the anti-patterns apply across languages and test frameworks.

## Iron Laws

```
1. Do not test mock mechanics unless collaborator interaction is the behavior contract.
2. Never add fake test-only business methods to production classes.
3. Never mock without understanding dependencies and side effects.
4. Never let mocks hide the real contract.
```

## Anti-Pattern 1: Testing Mock Mechanics Instead of the Contract

**Violation:**

```typescript
test('renders sidebar', () => {
  render(<Page />);
  expect(screen.getByTestId('sidebar-mock')).toBeInTheDocument();
});
```

This verifies that the mock exists. It says little about whether `Page` behaves correctly because mock existence is not the contract being tested.

**Fix:**

```typescript
test('renders page navigation', () => {
  render(<Page />);
  expect(screen.getByRole('navigation')).toBeInTheDocument();
});
```

Gate:

```
Before asserting on any mock element:
  Ask: "Am I testing observable behavior, a required collaborator interaction, or only mock existence?"
  If only mock existence, delete the assertion or unmock the collaborator.

  If a child component is mocked to isolate a slow or complex dependency,
  assert the parent behavior, user-visible result, or interaction effect,
  not that the mock label appeared.
```

## Anti-Pattern 2: Test-Only Methods in Production

**Violation:**

```typescript
class Session {
  async destroy() {
    await this.workspaceManager?.destroyWorkspace(this.id);
  }
}
```

If `destroy()` exists only for tests, production code now exposes a fake lifecycle API.

**Fix:**

```typescript
export async function cleanupSession(session: Session) {
  const workspace = session.getWorkspaceInfo();
  if (workspace) {
    await workspaceManager.destroyWorkspace(workspace.id);
  }
}
```

Put test cleanup in test utilities unless the production object truly owns that lifecycle.

Do not expose fake business APIs only because tests need a handle. Framework-provided test hooks, dependency injection seams, or diagnostic APIs can be valid when they are explicitly designed, named, and bounded. A new production-visible API must have a production purpose or a clear ownership rationale.

Gate:

```
Before adding a production method:
  Ask: "Is this only used by tests?"
  If yes, move it to test utilities or a bounded test harness.

  Ask: "Does this class own this resource lifecycle?"
  If no, put cleanup at the correct owner boundary.
```

## Anti-Pattern 3: Mocking Without Understanding

**Violation:**

```typescript
test('detects duplicate server', async () => {
  vi.mock('ToolCatalog', () => ({
    discoverAndCacheTools: vi.fn().mockResolvedValue(undefined)
  }));

  await addServer(config);
  await addServer(config);
});
```

If the mocked method writes config that duplicate detection depends on, the mock removed the behavior the test needs.

**Fix:**

Mock at the slow or unsafe boundary, not at the behavior boundary under test.

```typescript
test('detects duplicate server', async () => {
  vi.mock('MCPServerManager');

  await addServer(config);

  await expect(addServer(config)).rejects.toThrow(/duplicate/i);
});
```

Gate:

```
Before mocking any method:
  1. What side effects does the real method have?
  2. Does this test depend on any of those side effects?
  3. What is the narrowest slow, external, or unsafe boundary to fake?

If unsure, run with the real implementation first when safe.
```

## Anti-Pattern 4: Incomplete Mocks

**Violation:**

```typescript
const mockResponse = {
  status: 'success',
  data: { userId: '123', name: 'Alice' }
};
```

Partial mocks hide structural assumptions. Downstream code may rely on omitted fields and tests will still pass.

**Fix:**

```typescript
const mockResponse = {
  status: 'success',
  data: { userId: '123', name: 'Alice' },
  metadata: { requestId: 'req-789', timestamp: 1234567890 }
};
```

Mirror the real contract for fields the system may consume. Do not copy an entire real response just to look complete; include the fields needed for the behavior and enough surrounding structure to preserve the contract. If the real contract is unclear, find docs, fixtures, captured responses, or schema definitions before mocking.

Gate:

```
Before inventing test data:
  Ask: "Can I reuse an existing fixture, factory, schema, or captured example?"
  If yes, start there and trim only what the system cannot observe.
```

## Anti-Pattern 5: Integration Tests as Afterthought

**Violation:**

```text
Implementation complete.
No tests written.
Ready for testing.
```

Testing is part of implementation. For a behavior change, the regression test should exist before the fix.

**Fix:**

```text
1. Write failing test.
2. Verify valid RED.
3. Implement minimal fix.
4. Verify GREEN.
5. Refactor while green.
```

## Anti-Pattern 6: Fixed Sleeps and Timing Guesses

**Violation:**

```typescript
await page.waitForTimeout(600);
expect(await page.locator('[data-testid="result"]').count()).toBe(3);
```

Fixed sleeps create flaky tests because they wait for time, not for the required condition.

**Fix:**

```typescript
await expect(page.locator('[data-testid="result"]')).toHaveCount(3);
```

Wait for a specific UI state, event, response, file, or observable condition.

## Anti-Pattern 7: Testing Implementation Details

**Violation:**

```typescript
test('normalizes input', () => {
  const service = new UserService();
  const spy = vi.spyOn(service as any, 'normalizeName');

  service.createUser(' Alice ');

  expect(spy).toHaveBeenCalledWith(' Alice ');
});
```

This locks the test to a private helper instead of the behavior callers depend on.

**Fix:**

```typescript
test('stores normalized user names', () => {
  const service = new UserService();

  const user = service.createUser(' Alice ');

  expect(user.name).toBe('Alice');
});
```

Assert outputs, state changes, emitted events, responses, persisted data, or UI that users or callers can observe.

Gate:

```
Before asserting on a private method, internal state, helper call, or exact call count:
  Ask: "Would this still matter if the implementation changed but behavior stayed correct?"
  If no, assert the observable behavior instead.
```

## Anti-Pattern 8: Shared Mutable Fixtures and Order Dependence

**Violation:**

```typescript
const users: User[] = [];

test('creates a user', () => {
  users.push(createUser('Alice'));
  expect(users).toHaveLength(1);
});

test('lists created users', () => {
  expect(users[0].name).toBe('Alice');
});
```

The second test depends on the first test running before it. Reordering, retrying, or parallel execution can break the suite.

**Fix:**

```typescript
test('lists created users', () => {
  const users = [createUser('Alice')];

  expect(users[0].name).toBe('Alice');
});
```

Each test should own its setup and cleanup. Use factories, fresh fixtures, isolated databases, temporary directories, or per-test reset hooks when shared infrastructure is required.

Gate:

```
Before sharing mutable state across tests:
  Ask: "Can this test pass when run alone, after another test, or in parallel?"
  If no, move setup into the test or reset state before each run.
```

## When Mocks Become Too Complex

Warning signs:

- Mock setup dominates the test and obscures the behavior or expected result.
- The test breaks when an unrelated mock changes.
- The test fails when the mock is removed but not because of the intended behavior.
- You cannot explain why each mock is required.
- Mocks omit fields from the real contract.

Consider an integration test, real collaborator, fixture, fake service, or dependency injection instead.

## Quick Reference

| Anti-Pattern | Fix |
|--------------|-----|
| Assert on incidental mock mechanics | Test observable behavior, a required interaction contract, or unmock |
| Test-only production methods | Move cleanup/setup to test utilities |
| Mock without understanding | Understand side effects, mock at the narrow boundary |
| Incomplete mocks | Mirror the real contract |
| Tests after implementation | Use RED before the behavior change |
| Fixed sleeps | Wait for specific observable conditions |
| Implementation detail assertions | Assert observable behavior |
| Shared mutable fixtures | Give each test isolated setup and cleanup |
| Over-complex mocks | Prefer integration tests or simpler boundaries |

## Red Flags

- Assertion checks for `*-mock` test IDs.
- Methods only called from test files.
- Mock setup obscures the behavior, duplicates large portions of the real contract, or cannot be explained clearly.
- Test passes even when the behavior boundary is broken.
- Mocking "just to be safe."
- Test data omits fields the real dependency returns.
- Fixed waits replace condition-based assertions.
- Assertions target private methods, internal state, or helper call counts.
- Tests pass only when run in a specific order.
- Global fixtures are mutated without per-test reset.

## Bottom Line

Mocks are tools to isolate external, slow, unsafe, or nondeterministic dependencies. They should preserve the behavior contract the test depends on.
