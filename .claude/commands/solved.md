---
description: Explain, classify, file, commit and push a solved LeetCode/CodeChef problem
argument-hint: "[file path, problem URL, or nothing to paste code]"
allowed-tools: Bash, Read, Write, Edit, Glob, Grep
---

# /solved — file a freshly solved problem

The user just solved a problem and wants it documented and pushed. Argument
given (may be empty): `$ARGUMENTS`

## Step 1 — get the code

Depending on what the argument is:

- **A file path** → read it.
- **A problem URL** → the code should be in the message too; if it is not, ask
  for it.
- **Empty** → check `inbox/` for unprocessed files first. If the inbox is empty
  and no code was pasted, ask the user to paste their accepted solution.

If the problem cannot be identified from the code alone, ask — do not guess a
problem number. A wrong `@id` corrupts the index.

## Step 2 — write the explanation header

Match the existing files exactly. Read one first (e.g.
`LeetCode/Easy/27.Remove_Element.cpp`) and mirror its structure:

1. Ruled title line: platform, id, title, difficulty
2. `@tag` metadata block, aligned:
   `@platform @id @title @difficulty @topics @pattern @url`
3. `PROBLEM` — restate plainly, with a small worked example
4. `INTUITION` — the key idea and *why* it works
5. `WALKTHROUGH` — annotate this specific code, then a dry run on a concrete
   input showing intermediate state
6. `COMPLEXITY` — time and space, each justified in one line
7. `EDGE CASES` — what could break it and how the code handles it
8. A closing section on the better/optimal approach with a short code sketch —
   **only if** this solution is not already optimal

Comment syntax: `/* ... */` for C-family, `""" ... """` for Python.
Target 60–110 lines. Be honest — if the code has dead code, a bug, or violates
the problem's stated complexity requirement, say so plainly. That is the whole
value of the file when they re-read it in six months.

Use the platform's own topic vocabulary for `@topics` (`Array`, `Hash Table`,
`Two Pointers`, `Binary Search`, `Dynamic Programming`, …) so the index groups
cleanly rather than fragmenting into near-duplicate tags.

## Step 3 — file it

- LeetCode → `LeetCode/{Easy|Medium|Hard}/{id}.{Title_With_Underscores}.{ext}`
- CodeChef → `CodeChef/{bucket}_Difficulty_Rating/{next-number}.{Title}.{ext}`
  where bucket is one of `500`, `500_to_1000`, `1000_to_1400`, `1400_to_1600`,
  `1600_to_1800`, `1800_to_2000`, `2000_to_2500`.

The header goes **above** the code. Leave the user's code exactly as they wrote
it — do not reformat, rename variables, or "improve" it. Suggested improvements
belong in the header's final section, never in the code itself.

If the destination file already exists, stop and ask whether to overwrite.

## Step 4 — regenerate and commit

```bash
python scripts/build_index.py
python scripts/update_stats.py
git add -A
git commit -m "solve: <Problem Title>"
git push
```

Commit as the user's own git identity — never `--author` as a bot, or the
commit will not count toward their contribution graph.

If `inbox/` contained the file, it is deleted as part of filing.

## Step 5 — report

One or two lines: where the file landed, its topics, and confirmation of the
push. If you flagged a real problem with the solution (wrong complexity class,
a bug, dead code), say so — that is worth their attention now rather than in
six months.
