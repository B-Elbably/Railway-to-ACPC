# use to move all cpp & py files
# excute wihh : ./move_files.sh ./solved/
#!/bin/bash

# Check argument
if [ $# -lt 1 ]; then
    echo "Usage: $0 <destination_folder>"
    exit 1
fi

DEST="$1"  # folder to move files into

# create destination folder if it doesn't exist
mkdir -p "$DEST"

# move all .cpp and .py files except train.cpp and train.py from current folder into DEST
find . -maxdepth 1 \( -name "*.cpp" -o -name "*.py" \) \
    ! -name "train.cpp" ! -name "train.py" \
    -exec mv {} "$DEST" \;

echo "Moved .cpp and .py files (except train.*) into $DEST"