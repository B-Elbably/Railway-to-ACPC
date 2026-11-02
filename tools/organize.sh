#!/usr/bin/env bash
# organize.sh - safe wrapper for the repository's grouped problem organizer
# This keeps files under solved/<platform>/<group>/... rather than creating a
# separate folder for every single file.

set -euo pipefail

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd -- "$SCRIPT_DIR/.." && pwd)"
cd "$REPO_ROOT"

if ! command -v python3 >/dev/null 2>&1; then
    echo "python3 is required but was not found in PATH." >&2
    exit 1
fi

if [[ ! -f tools/cph.py ]]; then
    echo "tools/cph.py was not found in $REPO_ROOT." >&2
    exit 1
fi

show_help() {
    echo "Usage: ./tools/organize.sh [command] [options]"
    echo ""
    echo "Commands:"
    echo "  all                  Run full organization (default)"
    echo "  move                 Move files into solved/<platform>/<group>/..."
    echo "  sort                 Sort files by contest/category"
    echo "  clean                Remove empty directories"
    echo "  stats                Show organization statistics"
    echo "  road-to-2027         Put current C++ files into solved/road to 2027/<name>/main.cpp"
    echo ""
    echo "Options:"
    echo "  -n, --dry-run   Preview without changing files"
    echo "  -h, --help      Show this help"
    echo ""
    echo "Examples:"
    echo "  ./tools/organize.sh"
    echo "  ./tools/organize.sh all --dry-run"
    echo "  ./tools/organize.sh road-to-2027"
    echo "  ./tools/organize.sh sort"
    echo "  ./tools/organize.sh stats"
}

run_cph() {
    python3 tools/cph.py "$@"
}

cmd="${1:-all}"
shift || true

case "$cmd" in
    all)
        dry_run=false
        while [[ $# -gt 0 ]]; do
            case "$1" in
                -n|--dry-run)
                    dry_run=true
                    ;;
                -h|--help)
                    show_help
                    exit 0
                    ;;
                *)
                    echo "Unknown option for 'all': $1" >&2
                    show_help >&2
                    exit 1
                    ;;
            esac
            shift
        done

        echo "Organizing files by judge/contest group..."
        if [[ "$dry_run" == true ]]; then
            run_cph move --dry-run
            run_cph sort --dry-run
            echo "Skipping clean because dry-run should not modify the filesystem."
        else
            run_cph move
            run_cph sort
            run_cph clean
        fi
        run_cph stats
        echo "Done."
        ;;
    move|sort|clean|stats|fetch)
        run_cph "$cmd" "$@"
        ;;
    road-to-2027|road_to_2027)
        target_root="$REPO_ROOT/solved/road to 2027"
        mkdir -p "$target_root"
        dry_run=false
        while [[ $# -gt 0 ]]; do
            case "$1" in
                -n|--dry-run)
                    dry_run=true
                    ;;
                -h|--help)
                    show_help
                    exit 0
                    ;;
                *)
                    echo "Unknown option for road-to-2027: $1" >&2
                    show_help >&2
                    exit 1
                    ;;
            esac
            shift
        done

        moved=0
        shopt -s nullglob
        for file in "$REPO_ROOT"/*.cpp "$REPO_ROOT"/*.cc "$REPO_ROOT"/*.cxx; do
            [[ -f "$file" ]] || continue
            base="$(basename "$file")"
            stem="${base%.*}"
            ext="${base##*.}"
            dest_dir="$target_root/$stem"
            mkdir -p "$dest_dir"
            dest="$dest_dir/main.$ext"

            if [[ -e "$dest" ]]; then
                echo "Skipping $base: $dest already exists"
                continue
            fi

            if [[ "$dry_run" == true ]]; then
                echo "Would move: $base -> $dest"
                continue
            fi

            mv "$file" "$dest"
            echo "Moved: $base -> $dest"
            moved=$((moved + 1))
        done
        echo "Done. Moved $moved C++ file(s) into solved/road to 2027."
        ;;
    -h|--help)
        show_help
        ;;
    *)
        echo "Unknown command: $cmd" >&2
        show_help >&2
        exit 1
        ;;
esac
