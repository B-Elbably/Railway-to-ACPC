#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    char prev = '0';
    int res = 0;
    for (auto &c : s) {
        if (c != prev) {
            res = 0;
        }
        prev = c;
        res++;
        ans = max(ans, res);
    }
    ans = max(ans, res);
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
