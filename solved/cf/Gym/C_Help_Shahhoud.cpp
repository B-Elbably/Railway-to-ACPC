#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    if (s[n / 2] != t[n / 2]) {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    for (int i = 0; i < n / 2; ++i) {
        if (ans % 2 == 0) {
            if (s[i] == t[i] && s[n - 1 - i] == t[n - 1 - i]) {
                continue;
            } else if (s[i] == t[n - 1 - i] && s[n - 1 - i] == t[i]) {
                ans++;
            } else {
                cout << -1 << endl;
                return;
            }
        } else {
            if (s[i] == t[n - 1 - i] && s[n - 1 - i] == t[i]) {
                continue;
            } else if (s[i] == t[i] && s[n - 1 - i] == t[n - 1 - i]) {
                ans++;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    } 
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
