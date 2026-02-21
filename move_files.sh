#!/bin/bash

# Enhanced move_files.sh - Intelligently detects source using .cph files and URL patterns
# Supports: Codeforces, CSES, USACO, AtCoder, SPOJ, HackerRank, LeetCode, and more
#
# Usage: ./move_files.sh [OPTIONS]
#   --dry-run    Show what would be moved without actually moving
#   --verbose    Show detailed detection info
#   --help       Show this help message

DEST="./solved"
CPH_DIR="./.cph"
DRY_RUN=false
VERBOSE=false

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        --dry-run|-n)
            DRY_RUN=true
            shift
            ;;
        --verbose|-v)
            VERBOSE=true
            shift
            ;;
        --help|-h)
            echo "Usage: ./move_files.sh [OPTIONS]"
            echo "  --dry-run, -n   Show what would be moved without actually moving"
            echo "  --verbose, -v   Show detailed detection info"
            echo "  --help, -h      Show this help message"
            exit 0
            ;;
        *)
            echo "Unknown option: $1"
            exit 1
            ;;
    esac
done

# Create destination folders
mkdir -p "$DEST/cf" "$DEST/cf/edu" "$DEST/cf/problem-set" \
         "$DEST/usaco" "$DEST/cses" "$DEST/atcoder" \
         "$DEST/spoj" "$DEST/hackerrank" "$DEST/leetcode" "$DEST/other"

# Enable nullglob and extglob
shopt -s nullglob extglob

# Color codes for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to find the .cph/.prob file for a given source file
find_cph_file() {
    local filename="$1"
    # CPH files are named like: .filename_hash.prob
    local cph_file=$(find "$CPH_DIR" -name ".$filename*" -type f 2>/dev/null | head -1)
    echo "$cph_file"
}

# Function to extract URL from .cph file
get_url_from_cph() {
    local cph_file="$1"
    if [[ -f "$cph_file" ]]; then
        # Extract URL using grep and sed (handles JSON)
        grep -o '"url":"[^"]*"' "$cph_file" 2>/dev/null | sed 's/"url":"//;s/"$//' | head -1
    fi
}

# Function to extract group from .cph file
get_group_from_cph() {
    local cph_file="$1"
    if [[ -f "$cph_file" ]]; then
        grep -o '"group":"[^"]*"' "$cph_file" 2>/dev/null | sed 's/"group":"//;s/"$//' | head -1
    fi
}

# Function to determine destination based on GROUP (primary) and URL (fallback)
get_destination_from_cph() {
    local group="$1"
    local url="$2"
    
    if [[ -z "$group" && -z "$url" ]]; then
        echo ""
        return
    fi
    
    # PRIMARY: Check group field (more reliable, contains website names)
    # Group examples: "Codeforces - Round 123", "CSES - CSES Problem Set", "USACO - Bronze", "AtCoder - ABC 164"
    
    local group_lower=$(echo "$group" | tr '[:upper:]' '[:lower:]')
    
    # Codeforces detection from group
    if [[ "$group_lower" == *"codeforces"* ]]; then
        if [[ "$group_lower" == *"educational"* ]] || [[ "$group_lower" == *"edu "* ]]; then
            echo "$DEST/cf/edu/"
        else
            echo "$DEST/cf/"
        fi
        return
    fi
    
    # CSES detection from group
    if [[ "$group_lower" == *"cses"* ]]; then
        echo "$DEST/cses/"
        return
    fi
    
    # USACO detection from group
    if [[ "$group_lower" == *"usaco"* ]]; then
        echo "$DEST/usaco/"
        return
    fi
    
    # AtCoder detection from group
    if [[ "$group_lower" == *"atcoder"* ]]; then
        echo "$DEST/atcoder/"
        return
    fi
    
    # SPOJ detection from group
    if [[ "$group_lower" == *"spoj"* ]]; then
        echo "$DEST/spoj/"
        return
    fi
    
    # HackerRank detection from group
    if [[ "$group_lower" == *"hackerrank"* ]]; then
        echo "$DEST/hackerrank/"
        return
    fi
    
    # LeetCode detection from group
    if [[ "$group_lower" == *"leetcode"* ]]; then
        echo "$DEST/leetcode/"
        return
    fi
    
    # CodeChef detection from group
    if [[ "$group_lower" == *"codechef"* ]]; then
        echo "$DEST/codechef/"
        return
    fi
    
    # Timus detection from group
    if [[ "$group_lower" == *"timus"* ]]; then
        echo "$DEST/timus/"
        return
    fi
    
    # DMOJ detection from group
    if [[ "$group_lower" == *"dmoj"* ]]; then
        echo "$DEST/dmoj/"
        return
    fi
    
    # Kattis detection from group
    if [[ "$group_lower" == *"kattis"* ]]; then
        echo "$DEST/kattis/"
        return
    fi
    
    # VJudge detection from group
    if [[ "$group_lower" == *"vjudge"* ]]; then
        echo "$DEST/other/"
        return
    fi
    
    # FALLBACK: Check URL if group didn't match
    if [[ -n "$url" ]]; then
        case "$url" in
            *codeforces.com*)
                if [[ "$group_lower" == *"educational"* ]]; then
                    echo "$DEST/cf/edu/"
                else
                    echo "$DEST/cf/"
                fi
                ;;
            *cses.fi*) echo "$DEST/cses/" ;;
            *usaco.org* | *usaco.guide*) echo "$DEST/usaco/" ;;
            *atcoder.jp*) echo "$DEST/atcoder/" ;;
            *spoj.com*) echo "$DEST/spoj/" ;;
            *hackerrank.com*) echo "$DEST/hackerrank/" ;;
            *leetcode.com*) echo "$DEST/leetcode/" ;;
            *codechef.com*) echo "$DEST/codechef/" ;;
            *acm.timus.ru* | *timus*) echo "$DEST/timus/" ;;
            *dmoj.ca*) echo "$DEST/dmoj/" ;;
            *kattis.com*) echo "$DEST/kattis/" ;;
            *) echo "" ;;
        esac
        return
    fi
    
    echo ""
}

# Function to fallback to filename-based detection
get_destination_from_filename() {
    local filename="$1"
    
    # USACO: Starts with "Problem_" (e.g., Problem_1_Milk_Pails.cpp)
    if [[ "$filename" == Problem_* ]]; then
        echo "$DEST/usaco/"
        return
    fi
    
    # CSES: No prefix letter, underscore-separated words (e.g., Apple_Division.cpp)
    # Typically just descriptive names without letter prefix
    if [[ "$filename" =~ ^[A-Z][a-z]+_[A-Z] ]] && [[ ! "$filename" =~ ^[A-Z]_[A-Z] ]]; then
        echo "$DEST/cses/"
        return
    fi
    
    # Codeforces: Letter + underscore (e.g., A_Problem_Name.cpp, B_Name.cpp)
    # Also handles numbered versions like A1_, C_1_, etc.
    if [[ "$filename" =~ ^[A-Z][0-9]*_[0-9]*_?[A-Z] ]] || [[ "$filename" =~ ^[A-Z]_[A-Z] ]]; then
        echo "$DEST/cf/"
        return
    fi
    
    # AtCoder: Similar to CF but often without underscore after letter
    # e.g., abc164_d format is less common in filenames
    
    # Default: empty (will be handled as unknown)
    echo ""
}

# Counters for summary
moved_count=0
skipped_count=0
unknown_count=0

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}   Intelligent File Mover v2.0${NC}"
echo -e "${BLUE}========================================${NC}"
echo ""

# Process all .cpp and .py files
for file in *.cpp *.py; do
    # Skip train files
    if [[ "$file" == "train.cpp" || "$file" == "train.py" ]]; then
        echo -e "${YELLOW}[SKIP]${NC} $file (template file)"
        ((skipped_count++))
        continue
    fi
    
    destination=""
    detection_method=""
    
    # Try to find .cph file first (most accurate)
    cph_file=$(find_cph_file "$file")
    
    if [[ -n "$cph_file" && -f "$cph_file" ]]; then
        url=$(get_url_from_cph "$cph_file")
        group=$(get_group_from_cph "$cph_file")
        destination=$(get_destination_from_cph "$group" "$url")
        
        if [[ -n "$destination" ]]; then
            detection_method="cph (group: $group)"
        fi
    fi
    
    # Fallback to filename-based detection
    if [[ -z "$destination" ]]; then
        destination=$(get_destination_from_filename "$file")
        if [[ -n "$destination" ]]; then
            detection_method="filename pattern"
        fi
    fi
    
    # Move the file or report unknown
    if [[ -n "$destination" ]]; then
        if [[ "$DRY_RUN" == true ]]; then
            echo -e "${GREEN}[WOULD MOVE]${NC} $file -> $destination (via $detection_method)"
            ((moved_count++))
        else
            # Create directory if needed (in case of dynamic creation)
            mkdir -p "$destination"
            
            # Check if file already exists at destination (prevent overwrite)
            if [[ -f "${destination}${file}" ]]; then
                echo -e "${YELLOW}[EXISTS]${NC} $file already exists in $destination - skipping"
                ((skipped_count++))
            else
                mv "$file" "$destination"
                echo -e "${GREEN}[MOVED]${NC} $file -> $destination (via $detection_method)"
                ((moved_count++))
                
                # Also copy the .cph file if it exists (keep original)
                if [[ -n "$cph_file" && -f "$cph_file" ]]; then
                    # Get the destination .cph directory
                    dest_cph_dir="${destination}.cph"
                    mkdir -p "$dest_cph_dir"
                    cp "$cph_file" "$dest_cph_dir/" 2>/dev/null
                fi
            fi
        fi
    else
        echo -e "${RED}[UNKNOWN]${NC} $file - Could not determine source"
        ((unknown_count++))
    fi
done

echo ""
echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}   Summary${NC}"
echo -e "${BLUE}========================================${NC}"
echo -e "  ${GREEN}Moved:${NC}   $moved_count files"
echo -e "  ${YELLOW}Skipped:${NC} $skipped_count files"
echo -e "  ${RED}Unknown:${NC} $unknown_count files"
echo ""

if [[ $unknown_count -gt 0 ]]; then
    echo -e "${YELLOW}Tip:${NC} Unknown files may need manual sorting or lack .cph metadata."
    echo "     Run 'competitive companion' browser extension while opening problems to generate .cph files."
fi