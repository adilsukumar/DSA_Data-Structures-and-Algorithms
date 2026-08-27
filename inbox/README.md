# 📥 Inbox

Drop raw solution files here. Anything in this folder gets picked up, explained,
filed into the right folder, indexed, committed and pushed.

## How to use it

1. Solve a problem on LeetCode or CodeChef.
2. Copy your accepted code.
3. Save it here as any filename with the right extension — `x.cpp`, `sol.py`,
   `whatever.java`. The name does not matter; it gets renamed automatically.
4. Either wait for the nightly sweep, or trigger it now:

```bash
python scripts/process_inbox.py
```

## If the problem is ambiguous

Some solutions are hard to identify from code alone (especially CodeChef, where
the code is often just a few lines). Drop a matching `.url` file next to it:

```
inbox/mysol.cpp
inbox/mysol.url     <-- contains the problem URL or title
```

That hint gets passed along and pins down the identification.

## Rules

- A file that fails to process **stays here**. Nothing is ever deleted on
  failure, so you can always re-run.
- This `README.md` is ignored by the pipeline — only source files are picked up.
- Once a file is successfully filed, it is removed from here.
