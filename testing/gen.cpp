#include <bits/stdc++.h>
using namespace std;

int randInt(int l, int r) {
    return l + rand() % (r - l + 1);
}

// generate array of length n with unique values between 1 and maxVal
vector<int> generateArray(int n, int maxVal) {
    vector<int> arr;
    set<int> used;
    for (int i = 0; i < n; i++) {
        int x;
        do {
            x = randInt(1, maxVal);
        } while (used.count(x));
        used.insert(x);
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
    printf("1\n"); // number of test cases
    int n = 5;
    int maxVal = 6;
    printf("%d\n", n);

    vector<int> a = generateArray(n, maxVal);
    vector<int> b = generateArray(n, maxVal);

    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    for (int i = 0; i < n; i++) printf("%d ", b[i]);
    printf("\n");

    return 0;
}
