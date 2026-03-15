#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e5 + 1;
int w[101], v[101];

void solve() {
    int n, W;
    cin >> n >> W;
    for (int i = 0; i < n; ++i) cin >> w[i] >> v[i];
    vector<int> dp(N, 1e15 + 5);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = N - 1; j >= v[i]; --j) {
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (dp[i] <= W) ans = i;
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
