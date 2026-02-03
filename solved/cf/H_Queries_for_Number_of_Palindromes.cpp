#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    string s; cin >> s;
    s = " " + s;
    int n = s.size();
    int dp[2][n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int l = n - 1; l >= 1; l--) {
        for (int r = l; r < n; r++) {
            dp[0][l][r] = s[l] == s[r] && (r - l <= 1 || dp[0][l + 1][r - 1]);
            dp[1][l][r] = dp[1][l + 1][r] + dp[1][l][r - 1]  + dp[0][l][r];
            dp[1][l][r] -= dp[1][l + 1][r - 1];
        }
    }
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << dp[1][l][r] << endl;
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}


// i ----> j ?? 
// [i + 1][j] . [i][j - 1] ?? 