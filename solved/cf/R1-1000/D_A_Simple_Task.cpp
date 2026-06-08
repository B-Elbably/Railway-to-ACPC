#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 20;
vector<int> adj[N];
int dp[N][1 << N];
int vis[N];
int n, m;

int dfs(int u, int mask, int start, int par) {
    int &ret = dp[u][mask];
    if (~ret) return ret;
    ret = 0;
    for (int v : adj[u]) {
        if (par == v) continue;
        if (vis[v]) continue;
        if (mask & (1 << v)) {
            ret += (v == start);
            continue;
        }
        ret += dfs(v, mask | (1 << v), start, u);
    }
    return ret;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dfs(i, 1 << i, i, -1);
        vis[i] = 1;
    }
    ans /= 2;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
