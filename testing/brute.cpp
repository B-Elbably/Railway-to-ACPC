#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string S;
    cin >> S;

    int Q;
    cin >> Q;

    while (Q--) {
        int L, R;
        cin >> L >> R;
        L--; R--;

        string T = S.substr(L, R - L + 1);
        int ops = 0;

        for (int i = 0; i < (int)T.size(); i++) {
            bool bad = false;

            if (i >= 1 && T[i] == T[i - 1]) bad = true;
            if (i >= 2 && T[i] == T[i - 2]) bad = true;

            if (bad) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if ((i >= 1 && c == T[i - 1]) ||
                        (i >= 2 && c == T[i - 2]))
                        continue;
                    T[i] = c;
                    break;
                }
                ops++;
            }
        }

        cout << ops << "\n";
    }

    return 0;
}
