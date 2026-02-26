#!/bin/bash
# organize.sh - Organize competitive programming files
# Usage: ./organize.sh [command] [options]

cd "$(dirname "$0")"

case "${1:-all}" in
    all)
        DRY=""; [[ "$2" == "-n" || "$2" == "--dry-run" ]] && DRY="--dry-run"
        echo "🚀 Organizing all files..."
        python3 cph.py move $DRY
        python3 cph.py sort $DRY
        python3 cph.py sort --platform cses $DRY
        python3 cph.py clean
        python3 cph.py stats
        echo "✅ Done!"
        ;;
    move|sort|clean|stats)
        python3 cph.py "$@"
        ;;
    -h|--help)
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
        ;;
    *)
        echo "Unknown command: $1 (use --help)"
        exit 1
        ;;
esac
