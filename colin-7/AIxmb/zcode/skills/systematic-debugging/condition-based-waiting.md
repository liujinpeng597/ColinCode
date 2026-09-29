# Condition-Based Waiting

## Overview

Flaky tests often wait for a guessed amount of time. This creates race conditions: tests pass on fast machines and fail under load or in CI.

**Core principle:** Wait for the condition you care about, not for a guessed delay.

## When to Use

Use this when:

- Tests use arbitrary delays such as `setTimeout`, `sleep`, or `time.sleep()`.
- Tests pass sometimes and fail under load or in CI.
- Tests wait for async operations, files, events, network responses, UI state, or background jobs.
- A failure looks timing-dependent but the real completion signal is observable.

Do not replace real timing assertions when timing is the behavior under test, such as debounce, throttle, retry backoff, or timeout behavior. In those cases, document why the time wait is required and prefer fake timers when available.

## Core Pattern

Before:

```typescript
await new Promise(resolve => setTimeout(resolve, 50));
const result = getResult();
expect(result).toBeDefined();
```

After:

```typescript
await waitFor(() => getResult() !== undefined, 'result to be available');
expect(getResult()).toBeDefined();
```

## Generic Helper

```typescript
async function waitFor<T>(
  condition: () => T | undefined | null | false,
  description: string,
  timeoutMs = 5000,
  intervalMs = 10
): Promise<T> {
  const startTime = Date.now();

  while (true) {
    const result = condition();
    if (result) return result;

    if (Date.now() - startTime > timeoutMs) {
      throw new Error(`Timeout waiting for ${description} after ${timeoutMs}ms`);
    }

    await new Promise(resolve => setTimeout(resolve, intervalMs));
  }
}
```

Adjust polling interval to the system. Fast unit tests may use short intervals; external services should use longer intervals.

## Patterns

| Scenario | Pattern |
|----------|---------|
| Event emitted | `waitFor(() => events.find(event => event.type === 'DONE'), 'DONE event')` |
| State change | `waitFor(() => machine.state === 'ready', 'machine ready')` |
| Count reached | `waitFor(() => items.length >= 5, 'five items')` |
| File created | `waitFor(() => fs.existsSync(path), 'file to exist')` |
| UI update | Use framework locator/assertion that waits for the UI condition |
| Background job | Poll job status or observe completion event |

## Common Mistakes

**Polling too fast:** `setTimeout(check, 1)` wastes CPU.

Fix: Use a reasonable interval.

**No timeout:** Infinite loops hide failures.

Fix: Always include a timeout with a clear error message.

**Stale data:** Reading state once before the loop means the condition never changes.

Fix: Call the getter inside the loop.

**Waiting for time after an event is already observable:** This still flakes under slow conditions.

Fix: Wait for the next observable condition.

## When a Time Wait Is Acceptable

Time waits are acceptable only when timing is part of the behavior.

```typescript
await waitFor(() => events.some(event => event.type === 'STARTED'), 'job to start');

// The system emits progress every 100ms. Wait for two intervals to verify
// intermediate progress behavior.
await new Promise(resolve => setTimeout(resolve, 220));

expect(progressEvents.length).toBeGreaterThanOrEqual(2);
```

Requirements:

1. First wait for the triggering condition.
2. Base the duration on documented behavior, not a guess.
3. Add a comment explaining why time is the behavior.
4. Prefer fake timers when the framework supports them.

## Debugging Flaky Waits

- Identify the condition the test actually needs.
- Add temporary diagnostics around event/state transitions.
- Replace sleeps with condition polling or framework waiting assertions.
- Run the test repeatedly or in parallel to confirm stability.

See `condition-based-waiting-example.ts` for a fuller TypeScript helper pattern.
