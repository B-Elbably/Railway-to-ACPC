#include <bits/stdc++.h>
using namespace std;

int randInt(int l, int r) {
    return l + rand() % (r - l + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));

    int n = randInt(5, 9);
    cout << n << "\n";

    for (int i = 0; i < n; i++) {
        cout << randInt(-5, 5) << " ";
    }
    cout << "\n";
}
