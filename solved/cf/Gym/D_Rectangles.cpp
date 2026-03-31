#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, 0));
    // vector<vector<int>> dp2(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> a[i][j];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = 1;
            if (i > 0 && a[i][j] == a[i-1][j]) {
                dp[i][j] += dp[i-1][j];
            } 
            
            int mn = dp[i][j];
            for (int k = j; k >= 0 && a[i][k] == a[i][j]; k--) {
                mn = min(mn, dp[i][k]);
                ans += mn;
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
}
