#!/usr/bin/env bash
# organize.sh - Organize competitive programming files
# Usage: ./organize.sh [command] [options]

set -euo pipefail

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

if ! command -v python3 >/dev/null 2>&1; then
    echo "python3 is required but was not found in PATH." >&2
    exit 1
fi

if [[ ! -f cph.py ]]; then
    echo "cph.py was not found in $SCRIPT_DIR." >&2
    exit 1
fi

show_help() {
    echo "Usage: ./organize.sh [command] [options]"
    echo ""
    echo "Commands:"
    echo "  all       Run full organization (default)"
    echo "  move      Move files to platform folders"
    echo "  sort      Sort files into categories"
    echo "  clean     Remove empty directories"
    echo "  stats     Show statistics"
    echo ""
    echo "Options:"
    echo "  -n, --dry-run   Preview without changes"
    echo ""
    echo "Examples:"
    echo "  ./organize.sh              # Full organization"
    echo "  ./organize.sh all -n       # Dry run"
    echo "  ./organize.sh sort         # Sort only"
    echo "  ./organize.sh stats        # Show stats"
}

run_cph() {
    python3 cph.py "$@"
}

case "${1:-all}" in
    all)
        dry_run=false
        for arg in "${@:2}"; do
            case "$arg" in
                -n|--dry-run)
                    dry_run=true
                    ;;
                -h|--help)
                    show_help
                    exit 0
                    ;;
                *)
                    echo "Unknown option for 'all': $arg" >&2
                    echo "Use --help for usage." >&2
                    exit 1
                    ;;
            esac
        done

        echo "Organizing all files..."
        if [[ "$dry_run" == true ]]; then
            run_cph move --dry-run
            run_cph sort --dry-run
            echo "Skipping 'clean' because dry-run should not modify the filesystem."
        else
            run_cph move
            run_cph sort
            run_cph clean
        fi
        run_cph stats
        echo "Done."
        ;;
    move|sort|clean|stats)
        run_cph "$@"
        ;;
    -h|--help)
        show_help
        ;;
    *)
        echo "Unknown command: $1" >&2
        echo "Use --help for usage." >&2
        exit 1
        ;;
esac
