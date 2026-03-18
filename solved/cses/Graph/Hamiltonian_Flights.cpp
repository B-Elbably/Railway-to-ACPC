#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n, m;
vector<vector<int>> a;
const int MOD = 1e9 + 7;
const int N = 20;
int dp[N][1 << N];
vector<int> adj[N];
int go(int i, int mask) {
    if (i == n - 1) return (mask == (1 << n) - 1);
    int &ret = dp[i][mask];
    if (~ret) return ret;
    ret = 0;
    for (int j = 0; j < n; j++) {
        if (!a[i][j]) continue;
        if (mask & (1 << j)) continue;
        ret += a[i][j] * go(j , mask | (1 << j));
        ret %= MOD;
    }
    return ret;
}

void solve() {
    cin >> n >> m;
    a.resize(n, vector<int>(n));
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        a[--u][--v]++;
    }
    cout << go(0, 1) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
