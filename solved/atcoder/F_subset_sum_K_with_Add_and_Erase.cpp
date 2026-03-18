#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int MOD = 998244353;

void solve() {
    int q, k;
    cin >> q >> k;
    vector<int> dp(k + 1, 0);
    dp[0] = 1; 
    while (q--){
        char type; int ai;
        cin >> type >> ai;
        if (type == '+') {
            for (int j = k; j >= ai; j--) {
                dp[j] = (dp[j] + dp[j - ai]) % MOD;
            }
        } else {
            for (int j = ai; j <= k; j++) {
                dp[j] = (dp[j] - dp[j - ai] + MOD) % MOD;
            }
        }
        cout << dp[k] << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
