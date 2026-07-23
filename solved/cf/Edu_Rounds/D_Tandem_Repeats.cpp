#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    string s; cin >> s;
    int n = s.size();
    
    for (int m = n / 2; m >= 1; --m) {
        int len = 2 * m;
        for (int i = 0; i <= n - len; ++i) {
            int ok = 1;
            for (int j = 0; j < m; ++j) {
                if (s[i + j] == '?') continue;
                if (s[i + j + m] == '?') continue;
                if (s[i + j] != s[i + j + m]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                cout << len << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}