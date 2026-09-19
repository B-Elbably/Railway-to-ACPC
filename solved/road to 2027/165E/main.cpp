#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 22;
int sup = (1 << N) - 1;
int dp[1 << N];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    memset(dp, -1, sizeof(dp));
    for (auto &x : a) cin >> x, dp[x] = x;
    for (int bit = 0; bit < N; bit++) {
        for (int mask = 0; mask < (1 << N); mask++) {
            if (!(mask & (1 << bit))) continue;
            if (~dp[mask]) continue;
            dp[mask] = dp[mask ^ (1 << bit)]; 
        }
    }
    for (int i = 0; i < n; i++) {
        int inv = sup & (~a[i]);
        cout << dp[inv] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
