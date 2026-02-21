#!/bin/bash

# organize_solved.sh - Organize files in solved folder using .cph metadata
# Groups files by: round/contest name OR month (for files with many in same month)
#
# Usage: ./organize_solved.sh [OPTIONS]
#   --dry-run    Show what would be done without actually doing it
#   --help       Show this help message

SOLVED_DIR="./solved"
CPH_DIR="./.cph"
DRY_RUN=false

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        --dry-run|-n)
            DRY_RUN=true
            shift
            ;;
        --help|-h)
            echo "Usage: ./organize_solved.sh [OPTIONS]"
            echo "  --dry-run, -n   Show what would be done without actually doing it"
            echo "  --help, -h      Show this help message"
            exit 0
            ;;
        *)
            echo "Unknown option: $1"
            exit 1
            ;;
    esac
done

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m'

# Function to find .cph file for a source file
find_cph_file() {
    local filename="$1"
    find "$CPH_DIR" -name ".$filename*" -type f 2>/dev/null | head -1
}

# Function to extract group from .cph file
get_group_from_cph() {
    local cph_file="$1"
    if [[ -f "$cph_file" ]]; then
        grep -o '"group":"[^"]*"' "$cph_file" 2>/dev/null | sed 's/"group":"//;s/"$//' | head -1
    fi
}

# Function to sanitize folder name (remove special chars, shorten)
sanitize_folder_name() {
    local name="$1"
    # Remove special characters, replace spaces with underscores
    echo "$name" | sed 's/[^a-zA-Z0-9 _-]//g' | sed 's/  */ /g' | sed 's/ /_/g' | cut -c1-50
}

# Function to extract round/contest name from group
extract_contest_name() {
    local group="$1"
    local current_subdir="$2"  # Current subdirectory the file is in
    local group_lower=$(echo "$group" | tr '[:upper:]' '[:lower:]')
    
    # Codeforces: Extract round number or contest name
    if [[ "$group_lower" == *"codeforces"* ]]; then
        # Examples:
        # "Codeforces - Codeforces Round 424 (Div. 2, rated...)" -> "Round_424"
        # "Codeforces - Educational Codeforces Round 93" -> "Edu_Round_93"
        # "Codeforces - Codeforces Global Round 7" -> "Global_Round_7"
        
        local base_dir=""
        
        # If file is already in edu/, problem-set/, etc., preserve that
        if [[ "$current_subdir" == *"/edu"* ]]; then
            base_dir="edu/"
        elif [[ "$current_subdir" == *"/problem-set"* ]]; then
            base_dir="problem-set/"
        fi
        
        if [[ "$group" =~ [Ee]ducational.*[Rr]ound[[:space:]]*([0-9]+) ]]; then
            echo "${base_dir}Edu_Round_${BASH_REMATCH[1]}"
        elif [[ "$group" =~ [Gg]lobal[[:space:]]*[Rr]ound[[:space:]]*([0-9]+) ]]; then
            echo "${base_dir}Global_Round_${BASH_REMATCH[1]}"
        elif [[ "$group" =~ [Rr]ound[[:space:]]*([0-9]+) ]]; then
            echo "${base_dir}Round_${BASH_REMATCH[1]}"
        elif [[ "$group" =~ [Dd]iv\.[[:space:]]*([0-9]+) ]]; then
            # Try to get contest number from URL or use generic
            echo "${base_dir}Div${BASH_REMATCH[1]}_Contest"
        else
            # Generic codeforces
            echo ""
        fi
        return
    fi
    
    # AtCoder: Extract contest name (ABC, ARC, AGC + number)
    if [[ "$group_lower" == *"atcoder"* ]]; then
        if [[ "$group" =~ (ABC|ARC|AGC|ATC)[[:space:]]*([0-9]+) ]]; then
            echo "${BASH_REMATCH[1]}_${BASH_REMATCH[2]}"
        elif [[ "$group" =~ [Bb]eginner[[:space:]]*[Cc]ontest[[:space:]]*([0-9]+) ]]; then
            echo "ABC_${BASH_REMATCH[1]}"
        else
            echo ""
        fi
        return
    fi
    
    # USACO: Extract division and contest
    if [[ "$group_lower" == *"usaco"* ]]; then
        # "USACO - USACO 2022 US Open Contest, Bronze" -> "2022_US_Open_Bronze"
        local year=""
        local division=""
        local contest=""
        
        if [[ "$group" =~ ([0-9]{4}) ]]; then
            year="${BASH_REMATCH[1]}"
        fi
        if [[ "$group_lower" =~ (bronze|silver|gold|platinum) ]]; then
            division=$(echo "${BASH_REMATCH[1]}" | sed 's/./\U&/')
        fi
        if [[ "$group_lower" =~ (january|february|december|us[[:space:]]*open) ]]; then
            contest=$(echo "${BASH_REMATCH[1]}" | sed 's/./\U&/' | sed 's/ /_/g')
        fi
        
        if [[ -n "$year" || -n "$division" ]]; then
            echo "${year}_${contest}_${division}" | sed 's/__*/_/g' | sed 's/^_//;s/_$//'
        else
            echo ""
        fi
        return
    fi
    
    # CSES: Usually just "CSES - CSES Problem Set", no subdivision needed
    if [[ "$group_lower" == *"cses"* ]]; then
        echo ""  # Keep flat for CSES
        return
    fi
    
    # Default: no subdivision
    echo ""
}

# Function to get file creation month from file modification time
get_file_month() {
    local filepath="$1"
    # Format: YYYY-MM
    stat -c %y "$filepath" 2>/dev/null | cut -d' ' -f1 | cut -d'-' -f1-2
}

# Counters
moved_count=0
skipped_count=0
no_cph_count=0

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}   Solved Files Organizer v1.0${NC}"
echo -e "${BLUE}========================================${NC}"
echo ""

if [[ "$DRY_RUN" == true ]]; then
    echo -e "${YELLOW}[DRY RUN MODE - No files will be moved]${NC}"
    echo ""
fi

# Process each platform folder
for platform_dir in "$SOLVED_DIR"/*/; do
    platform_name=$(basename "$platform_dir")
    
    # Skip if not a directory
    [[ ! -d "$platform_dir" ]] && continue
    
    echo -e "${CYAN}Processing: $platform_name${NC}"
    
    # Find all source files recursively (up to depth 3 for existing subfolders)
    while IFS= read -r -d '' filepath; do
        filename=$(basename "$filepath")
        current_dir=$(dirname "$filepath")
        relative_path="${filepath#$platform_dir}"
        
        # Find .cph file
        cph_file=$(find_cph_file "$filename")
        
        if [[ -z "$cph_file" || ! -f "$cph_file" ]]; then
            # No .cph file, try to organize by month
            file_month=$(get_file_month "$filepath")
            if [[ -n "$file_month" ]]; then
                # Only organize by month if there are many files
                target_dir="${platform_dir}${file_month}"
            else
                echo -e "  ${YELLOW}[NO CPH]${NC} $filename - keeping in place"
                ((no_cph_count++))
                continue
            fi
        else
            # Get group and extract contest name
            group=$(get_group_from_cph "$cph_file")
            contest_name=$(extract_contest_name "$group" "$current_dir")
            
            if [[ -n "$contest_name" ]]; then
                target_dir="${platform_dir}${contest_name}"
            else
                # No specific contest, keep in platform root or organize by month
                echo -e "  ${YELLOW}[KEEP]${NC} $filename (group: $group)"
                ((skipped_count++))
                continue
            fi
        fi
        
        # Normalize target directory
        target_dir=$(echo "$target_dir" | sed 's|//*|/|g')
        
        # Skip if already in correct location
        if [[ "$current_dir" == "${target_dir%/}" ]]; then
            echo -e "  ${YELLOW}[ALREADY]${NC} $filename in $contest_name"
            ((skipped_count++))
            continue
        fi
        
        # Check if file exists at destination
        if [[ -f "${target_dir}/${filename}" ]]; then
            echo -e "  ${YELLOW}[EXISTS]${NC} $filename already in ${target_dir}"
            ((skipped_count++))
            continue
        fi
        
        if [[ "$DRY_RUN" == true ]]; then
            echo -e "  ${GREEN}[WOULD MOVE]${NC} $filename -> $target_dir/"
        else
            mkdir -p "$target_dir"
            mv "$filepath" "$target_dir/"
            echo -e "  ${GREEN}[MOVED]${NC} $filename -> $target_dir/"
        fi
        ((moved_count++))
        
    done < <(find "$platform_dir" -maxdepth 3 -type f \( -name "*.cpp" -o -name "*.py" \) -print0 2>/dev/null)
    
    echo ""
done

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}   Summary${NC}"
echo -e "${BLUE}========================================${NC}"
echo -e "  ${GREEN}Moved:${NC}     $moved_count files"
echo -e "  ${YELLOW}Skipped:${NC}   $skipped_count files"
echo -e "  ${RED}No CPH:${NC}    $no_cph_count files"
echo ""

if [[ "$DRY_RUN" == true ]]; then
    echo -e "${YELLOW}Run without --dry-run to apply changes.${NC}"
fi
