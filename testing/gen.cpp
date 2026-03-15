#include <bits/stdc++.h>
using namespace std;

int randInt(int l, int r) {
    return l + rand() % (r - l + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));

    int n = randInt(2,4);
    cout << n << "\n";

    for (int i = 0; i < n; i++) {
        cout << randInt(0,1) << "";
    }
    cout << "\n";
}
