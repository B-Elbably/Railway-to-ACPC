#include <bits/stdc++.h>
using namespace std;

// Function to generate a random integer between l and r (inclusive)
int randInt(int l, int r) {
    return l + rand() % (r - l + 1);
}

// Function to generate an array of unique random integers
vector<int> generateArray(int n, int maxVal) {
    vector<int> arr;
    set<int> used; // To store unique numbers
    for (int i = 0; i < n; i++) {
        int x;
        do {
            x = randInt(1, maxVal);
        } while (used.count(x)); // Ensure uniqueness
        used.insert(x); // Mark the number as used
        arr.push_back(x);
    }
    return arr;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: ./gen <seed>\n";
        return 1;
    }

    // Set the random seed from the command line argument
    srand(atoi(argv[1]));

    // Generate the number of people (n pairs, 2*n total)
    int n = randInt(3, 20); // n between 2 and 10
    int maxVal = 1000; // Set max value based on n (to ensure enough unique values)

    // Output the test case format
    printf("1\n"); // Problem count (always 1)
    printf("%d\n", n); // Output n (the number of pairs)

    // Generate the array of 2 * n unique weights
    n *= 2; // 2*n people in total
    vector<int> a = generateArray(n, maxVal);

    // Output the generated array
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
