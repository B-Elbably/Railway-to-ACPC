#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int MOD = 1e9 + 7;
const int inv2 = (MOD + 1) / 2;
void solve() {
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum % 2) {
        cout << 0 << endl;
        return;
    }
    sum /= 2;
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= i; j--) {
            dp[j] += dp[j - i];
            dp[j] %= MOD;
        }
    }
    cout << dp[sum] * inv2 % MOD << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
