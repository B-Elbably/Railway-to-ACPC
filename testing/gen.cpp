#include <bits/stdc++.h>
using namespace std;

int randInt(int l, int r) {
    return l + rand() % (r - l + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));

    int N = randInt(1, 10);
    cout << N << "\n";

    string S;
    for (int i = 0; i < N; i++)
        S += char('a' + randInt(0, 2));
    cout << S << "\n";

    int Q = randInt(1, 10);
    cout << Q << "\n";

    while (Q--) {
        int l = randInt(1, N);
        int r = randInt(l, N);
        cout << l << " " << r << "\n";
    }
}
