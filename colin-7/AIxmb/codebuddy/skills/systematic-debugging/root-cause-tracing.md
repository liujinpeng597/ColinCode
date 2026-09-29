# Root Cause Tracing

## Overview

Bugs often appear far away from their source. The failing line may only be where bad data is consumed. Trace backward through calls, data flow, and configuration until you find the original trigger.

**Core principle:** Fix at the source. Add guards at boundaries only after the source is understood.

## When to Use

Use this when:

- The error appears deep in a stack trace.
- A value is invalid but its origin is unclear.
- A file, database, network call, or external command is using the wrong path, ID, credential, config, or state.
- A test pollutes global state and the polluter is unknown.
- Multiple layers pass data before the failure occurs.

## Tracing Process

### 1. Observe the Symptom

Record the exact failure:

```text
Error: command ran in the wrong directory
Actual path: D:\repo\packages\core
Expected path: temp test workspace
```

### 2. Find the Immediate Cause

Ask what directly caused the failure:

```typescript
await execFileAsync('git', ['init'], { cwd: projectDir });
```

Immediate cause: `projectDir` is wrong or empty.

### 3. Trace One Caller Up

Ask:

- Who passed this value?
- What did they believe the value meant?
- Was it transformed?
- Was it read from config, environment, state, request data, or a fixture?

```text
gitInit(projectDir)
<- WorkspaceManager.create(projectDir)
<- Session.initializeWorkspace()
<- test setup creates Session
```

### 4. Keep Tracing Until the Source

Continue until you find where the bad value was created, not just forwarded.

```text
projectDir = ""
<- test context returned empty tempDir
<- tempDir was read before test setup ran
```

The source is the premature read, not the command invocation.

### 5. Prove the Source

Add the smallest useful diagnostic evidence:

```typescript
console.error('DEBUG projectDir before git init', {
  projectDir,
  cwd: process.cwd(),
  stack: new Error().stack,
});
```

Use safe logging. Do not print secrets, tokens, private data, or full production payloads.

### 6. Fix Source, Then Guard Boundaries

Fix the original trigger first. Then consider validation at boundaries that should never accept the bad value.

Good fixes:

- Prevent premature read.
- Validate required config at entry.
- Make invalid state unrepresentable.
- Add a regression test for the source behavior.

Symptom-only fixes:

- Defaulting empty path to current directory.
- Adding a retry without knowing why the call failed.
- Swallowing the error.

## Instrumentation Tips

- Log before the dangerous operation, not only after it fails.
- Include relevant path, ID, state, config key presence, environment name, and stack trace.
- Redact secrets and user data.
- Use test-visible output when debugging tests.
- Remove temporary logs after the fix unless they are safe and useful observability.

## Finding Polluting Tests

If a test pollutes global state and the polluter is unknown:

1. Run the suspected test file alone.
2. Run nearby files in groups.
3. Bisect the list until the smallest reproducing set is found.
4. Run tests one-by-one if needed.

If shell scripts are available, `find-polluter.sh` in this directory may help. On Windows or when shell scripts are unavailable, use the same bisection strategy manually with PowerShell or the project test runner.

## Boundary Questions

At each hop, ask:

- Is this value owned here or merely forwarded?
- What invariant should be true at this boundary?
- Is the invariant checked anywhere?
- Could another path bypass the check?
- Would this layer leak sensitive information if logged?

## Final Rule

```text
Symptom -> immediate cause -> caller -> source -> proof -> source fix -> boundary guards
```

Do not stop at the first line that throws.
