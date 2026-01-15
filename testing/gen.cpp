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
            x = randInt(0, maxVal);
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

    srand(atoi(argv[1]));

    int x = randInt(3, 100); 
    int n = randInt(0, 2);
    int m = randInt(0, 2);
    // int maxVal = 2; 
    printf("%d\n", 1); 
    printf("%d %d %d\n", x, n, m);
    // vector<int> a = generateArray(n, maxVal);

    // for (int i = 0; i < n; i++) {
        // printf("%d ", a[i]);
    // }
    // printf("\n");

    return 0;
}
