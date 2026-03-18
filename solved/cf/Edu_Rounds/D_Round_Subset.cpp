#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int dp[205][5500];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        int c2 = 0, c5 = 0;
        while (a[i] > 0 && a[i] % 2 == 0) { c2++; a[i] /= 2; }
        while (a[i] > 0 && a[i] % 5 == 0) { c5++; a[i] /= 5; }

        for (int j = k; j > 0; j--) {
            for (int s = 5200; s >= c5; s--) {
                if (~dp[j - 1][s - c5]) {
                    dp[j][s] = max(dp[j][s],
                                    dp[j - 1][s - c5] + c2);
                }
            }
        }
    }

    int ans = 0;
    for (int s = 0; s <= 5200; s++) {
        if (~dp[k][s]) {
            ans = max(ans, min(s, dp[k][s]));
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}