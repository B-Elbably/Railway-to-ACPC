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
| `have_to_study/` | Problems to revisit |
| `skipped/`, `ignored/` | Problems set aside |
| `problem-setting/` | Generator and solution for problem-setting practice |
| `testing/` | Stress-testing tools (brute force, generators, `stress.sh`) and a Python scratch template |
| `boards/` | Whiteboard notes from sessions |

## Workflow

New solutions start in the repository root. The organizer moves them into `solved/`:

```bash
python3 cph.py       # run commands directly (move, sort, clean, stats, fetch)
./organize.sh        # wrapper: move + sort + clean + stats
./organize.sh road-to-2027   # put root .cpp files into solved/road to 2027/<name>/main.cpp
```

`organize.sh` and `cph.py` must stay in the repository root because they resolve paths relative to their own location. `orgainze.sh` is a shortcut that forwards to `organize.sh`.

## Notes

- Compiled binaries from the CPH-NG extension (`.cph-ng/`) are not tracked.
- Add a `LICENSE` or `CONTRIBUTING.md` if you plan public collaboration.
