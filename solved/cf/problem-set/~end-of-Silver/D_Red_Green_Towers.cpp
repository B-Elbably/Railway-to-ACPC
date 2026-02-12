#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int MOD = 1e9 + 7;

void solve() {
    int r, g;
    cin >> r >> g;
    int h = 0;
    while ((h + 1) * (h + 2) / 2 <= r + g) h++;
    vector<int> dp(r + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = r; j >= i; j--) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }
    int ans = 0, total = h * (h + 1) / 2;
    for (int i = 0; i <= r; i++) {
        int need = total - i;
        if (need >= 0 && need <= g) {
            ans = (ans + dp[i]) % MOD;
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
