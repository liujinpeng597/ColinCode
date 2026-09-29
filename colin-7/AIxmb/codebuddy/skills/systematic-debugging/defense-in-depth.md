# Defense-in-Depth Validation

## Overview

After a root cause is understood, add validation at the boundaries where invalid data can enter or become dangerous. The goal is to make the bug hard to reintroduce without adding noisy checks everywhere.

**Core principle:** Fix the source first, then guard meaningful boundaries.

## When to Use

Use this after root cause investigation shows:

- Invalid input crossed multiple layers.
- A dangerous operation accepted unsafe state.
- Different code paths can reach the same boundary.
- Mocks or tests bypassed a real production check.
- A missing invariant caused data corruption, unsafe file operations, auth bypass, or bad external calls.

Do not use this as a substitute for root cause analysis. Adding guards without understanding the source often hides the bug.

## Boundary Layers

### 1. Entry Point Validation

Reject invalid input at API, CLI, UI, job, or public module boundaries.

```typescript
function createProject(name: string, workingDirectory: string) {
  if (!workingDirectory || workingDirectory.trim() === '') {
    throw new Error('workingDirectory cannot be empty');
  }

  if (!existsSync(workingDirectory)) {
    throw new Error(`workingDirectory does not exist: ${workingDirectory}`);
  }

  if (!statSync(workingDirectory).isDirectory()) {
    throw new Error(`workingDirectory is not a directory: ${workingDirectory}`);
  }
}
```

### 2. Domain or Business Invariants

Validate assumptions where the operation's meaning is known.

```typescript
function initializeWorkspace(projectDir: string, sessionId: string) {
  if (!projectDir) {
    throw new Error('projectDir required for workspace initialization');
  }

  if (!sessionId) {
    throw new Error('sessionId required for workspace initialization');
  }
}
```

### 3. Dangerous Operation Guards

Protect file deletion, network calls, credential use, migrations, signing, payments, external writes, and other high-impact operations.

```typescript
async function initializeGitRepository(directory: string) {
  if (process.env.NODE_ENV === 'test') {
    const normalized = normalize(resolve(directory));
    const tempRoot = normalize(resolve(tmpdir()));

    if (!normalized.startsWith(tempRoot)) {
      throw new Error(`Refusing git init outside temp dir during tests: ${directory}`);
    }
  }
}
```

### 4. Observability for Future Forensics

Add safe diagnostics where future failures would be hard to understand.

```typescript
logger.debug('About to initialize workspace', {
  hasProjectDir: Boolean(projectDir),
  sessionId,
});
```

Do not log secrets, tokens, private data, or full production payloads.

## Applying the Pattern

1. Trace the data flow from source to failure.
2. Fix the source of invalid data.
3. Identify boundaries where the invariant should be enforced.
4. Add the smallest useful validation at those boundaries.
5. Add tests for the source fix and important boundary guards.
6. Verify error messages are actionable and safe.

## Good Defense-in-Depth

- Validates real invariants.
- Lives at meaningful boundaries.
- Produces clear, safe errors.
- Has tests for bypass paths.
- Does not duplicate identical checks blindly.

## Bad Defense-in-Depth

- Adds null guards without knowing why null appears.
- Swallows errors.
- Converts invalid state into defaults that hide corruption.
- Logs sensitive data for debugging.
- Adds checks in every function without clarifying ownership.

## Review Questions

- Which layer owns this invariant?
- Can another path bypass the entry check?
- Does this guard protect a dangerous operation?
- Is the error actionable?
- Is the error safe to show or log?
- Does the test prove the guard catches a real bypass path?

## Final Rule

```text
Source fix first. Boundary guards second. Silent defaults never.
```
