<div align="center">

# Railway-to-ACPC

**A competitive programming workspace: contest-ready C++ templates, 870+ solved problems and automation scripts.**

![C++](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=cplusplus&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=flat-square&logo=python&logoColor=white)
![Bash](https://img.shields.io/badge/Bash-4EAA25?style=flat-square&logo=gnubash&logoColor=white)

</div>

## Why

Preparing for national-level contests takes volume and organization. This repo is the training archive behind that preparation: the solutions, the reusable algorithms and the scripts that keep a growing pile of files in order.

## Key features

- **870+ solutions** sorted by judge (Codeforces, CSES, AtCoder, USACO, SPOJ and more) and then by round or topic
- **50+ C++ templates** for graphs, trees, range queries, number theory, geometry and DP in `knowledge/`
- **Workspace automation:** a Python organizer and Bash wrapper that file new solutions automatically
- **Stress-testing kit:** brute-force, generator and `stress.sh` tools in `testing/`

## Quick start

```bash
git clone https://github.com/B-Elbably/Railway-to-ACPC.git
cd Railway-to-ACPC
./tools/organize.sh all --dry-run   # preview what the organizer would move
```

## Usage

New solutions start in the repository root. The organizer files them into `solved/`. The scripts find the repo root themselves, so run them from any directory:

```bash
./tools/organize.sh                 # move + sort + clean + stats
./tools/organize.sh road-to-2027    # root .cpp files -> solved/road to 2027/<name>/main.cpp
python3 tools/cph.py stats          # run organizer commands directly (move, sort, clean, stats, fetch)
```

`tools/orgainze.sh` is a shortcut that forwards to `organize.sh`.

## Project structure

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

> [!NOTE]
> Compiled binaries from the CPH-NG extension (`.cph-ng/`) are not tracked.

## Contact

Maintained by [Belal Elbably](https://github.com/B-Elbably) · [LinkedIn](https://linkedin.com/in/elbably) · [Codeforces](https://codeforces.com/profile/Belal.echo)
