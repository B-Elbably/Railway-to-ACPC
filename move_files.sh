#!/bin/bash

# 1. Set Destination to 'solved' inside the CURRENT folder
DEST="./solved"

# 2. Create folders (safe to run even if they exist)
mkdir -p "$DEST/cf" "$DEST/usaco" "$DEST/cses"

# 3. Enable nullglob so the loop doesn't break if no files exist
shopt -s nullglob

# 4. Loop through all .cpp and .py files
for file in *.cpp *.py; do
    
    # Skip specific files
    if [[ "$file" == "train.cpp" || "$file" == "train.py" ]]; then
        continue
    fi

    # LOGIC RULES
    if [[ "$file" == Problem_* ]]; then
        # USACO: Starts with "Problem_"
        mv "$file" "$DEST/usaco/"
        
    elif [[ "$file" =~ ^[0-9A-Za-z]+_ ]]; then
        # Codeforces: Starts with Alphanumeric + Underscore (e.g., 123A_ or B_)
        mv "$file" "$DEST/cf/"
        
    else
        # CSES: Everything else
        mv "$file" "$DEST/cses/"
    fi
done

echo "Done. Files moved to $DEST"