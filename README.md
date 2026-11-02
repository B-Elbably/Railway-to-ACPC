# Railway-to-ACPC

Personal competitive-programming workspace: contest-ready templates, solved problems, and a small set of maintenance scripts.

Primary language: C++ (with some Python).

## Layout

| Folder | Contents |
| --- | --- |
| `solved/` | Solutions grouped by judge (`cf`, `cses`, `atcoder`, `usaco`, `spoj`, `lightoj`, `vjudge`, `other`) and then by round or topic; `road to 2027/` holds current practice |
| `knowledge/` | Reusable algorithms and templates: graphs, trees, range queries, number theory, geometry, DP, misc |
| `GYMs/` | Contest archives and gym problems |
| `Topics-Sheets/` | Topic-based problem sheets (ACPC easy, geometry from CF and CSES) |
| `backlog/` | `have_to_study/` (problems to revisit), `skipped/` and `ignored/` (problems set aside) |
| `problem-setting/` | Generator and solution for problem-setting practice |
| `testing/` | Stress-testing tools (brute force, generators, `stress.sh`) and a Python scratch template |
| `boards/` | Whiteboard notes from sessions |
| `tools/` | `cph.py` (the organizer) and the `organize.sh` wrapper |

## Workflow

New solutions start in the repository root. The organizer moves them into `solved/`. Run everything from any directory; the scripts find the repo root themselves:

```bash
./tools/organize.sh                 # move + sort + clean + stats
./tools/organize.sh all --dry-run   # preview without changing files
./tools/organize.sh road-to-2027    # root .cpp files -> solved/road to 2027/<name>/main.cpp
python3 tools/cph.py stats          # run organizer commands directly (move, sort, clean, stats, fetch)
```

`tools/orgainze.sh` is a shortcut that forwards to `organize.sh`.

## Notes

- Compiled binaries from the CPH-NG extension (`.cph-ng/`) are not tracked.
- Add a `LICENSE` or `CONTRIBUTING.md` if you plan public collaboration.
