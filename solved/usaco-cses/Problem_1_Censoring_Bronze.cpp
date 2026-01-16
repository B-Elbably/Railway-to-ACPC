#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    string s, t;
    cin >> s >> t;

    string res;
    int m = t.size();

    for (char c : s) {
        res.push_back(c);
        if (res.size() >= m) {
            bool ok = res[res.size() - m] == t[0] && res[res.size() - 1] == t[m - 1];
            for (int i = 0; i < m; i++) {
                if (res[res.size() - m + i] != t[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                // remove t
                for (int i = 0; i < m; i++) {
                    res.pop_back();
                }
            }
        }
    }

    cout << res << "\n";
    return 0;
}
