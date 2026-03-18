#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 100001;
const int M = 101;
const int MOD = 1e9 + 7;
int dp[N][M];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    if (a[1] == 0) {
        for (int j = 1; j <= m; ++j) dp[1][j] = 1;
    } else {
        dp[1][a[1]] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        if (a[i]) {
            for (int k = -1; k <= 1; ++k) {
                if (a[i] + k >= 1 && a[i] + k <= m) {
                    dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] + k]) % MOD;
                }
            }
        } else {
            for (int j = 1; j <= m; ++j) {
                for (int k = -1; k <= 1; ++k) {
                    if (j + k >= 1 && j + k <= m) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j + k]) % MOD;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int j = 1; j <= m; ++j) {
        ans = (ans + dp[n][j]) % MOD;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
