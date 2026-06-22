# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

A personal LeetCode practice repository. Each problem gets its own top-level folder
named `<number>. <Title>` (e.g. `20. Valid Parentheses`, `242. Valid Anagram (Easy)`),
containing a single `Solution.cpp`.

## Solution file convention

Each `Solution.cpp` contains only the LeetCode `Solution` class — no `main()`, no
`#include` directives, no `using namespace std`. These are written to be pasted directly
into the LeetCode editor, which supplies the standard headers and `std` namespace. STL
types (`vector`, `string`, `stack`, `unordered_map`, etc.) are used unqualified by design.

Because the files are fragments, they do not compile standalone. To compile/run one
locally for testing, wrap it: add `#include <bits/stdc++.h>`, `using namespace std;`, and
a `main()` that constructs `Solution` and calls the method — then
`g++ -std=c++17 file.cpp -o sol && ./sol`. Do not commit that scaffolding back into
`Solution.cpp`.

## Working on problems

- When asked to solve or fix a problem, edit (or create) the matching `<number>. <Title>/Solution.cpp`.
- The existing solutions contain bugs/typos (e.g. `s,length()` instead of `s.length()`,
  `&&` where `||` is meant in `20. Valid Parentheses`). Treat them as in-progress work, not
  reference implementations — verify logic carefully rather than mirroring existing style.
- Match the in-file indentation style (the `Solution` class body is indented one extra level).
