#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> dp[i][j];
            dp[i][j] += dp[i][j - 1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int sum = 0;
            for (int x = max(0, i - k); x < min(n + 1, i + k + 1); x++){
                int r = j + (k - abs(x - i));
                int l = j - (k - abs(x - i));
                sum += dp[x][min(n, r)] - dp[x][max(0, l - 1)];
            }
            ans = max(ans, sum);
        }
    }
    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
