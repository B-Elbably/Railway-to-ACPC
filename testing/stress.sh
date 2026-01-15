#!/bin/bash
set -e

MAX_TESTS=2000

GEN="gen"        # gen.cpp
# GEN="gen_tree" # gen_tree.cpp

FINAL_FILE="final_result.txt"

# 🔴 CLEAN BEFORE EXECUTION (TXT + EXECUTABLES ONLY)
rm -f *.txt gen candy brute

echo "Compiling..."
g++ -O2 -march=native $GEN.cpp -o gen
g++ -O2 -march=native candy.cpp -o candy
g++ -O2 -march=native brute.cpp -o brute
echo "Compilation done"

echo "Using generator: $GEN"

for ((i=1;i<=MAX_TESTS;i++)); do
    printf "Test %d " "$i"

    ./gen $i > input.txt
    ./candy < input.txt > out1.txt
    ./brute < input.txt > out2.txt
    # sleep 0.2
    if diff -w out1.txt out2.txt > /dev/null; then
        echo -e "\e[32mOK\e[0m"
    else
        echo -e "\e[31mWA\e[0m"

        # 🟢 WRITE ONLY LAST FAILED TEST
        {
            echo "FAILED AT TEST $i"
            echo
            echo "INPUT"
            cat input.txt
            echo "--------------------"
            echo "CANDY"
            cat out1.txt
            echo "--------------------"
            echo "BRUTE"
            cat out2.txt
        } > "$FINAL_FILE"

        # 🔴 CLEAN TEMP FILES + EXECUTABLES (KEEP FINAL + CPP)
        rm -f input.txt out1.txt out2.txt gen candy brute

        echo "Fail saved in $FINAL_FILE"
        exit 0
    fi
done

# 🟢 ALL PASSED → REMOVE EVERYTHING EXCEPT CPP
rm -f *.txt gen candy brute
echo -e "\e[32mAll tests passed!\e[0m"
