#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> p(n), v(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> v[i];
    
    vector<int> dp(x + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= p[i]; j--) {
            dp[j] = max(dp[j], v[i] + dp[j - p[i]]);
        }
    }
    cout << dp[x] << endl;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
