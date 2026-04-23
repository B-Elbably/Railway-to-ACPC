#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 3e5 + 5;
const int MOD = 1e9 + 7;
vector<int> adj[N];
int color[N];
int dp[N][3];

void dfs(int u, int p) {
    if (~color[u]) dp[u][color[u]] = 1;
    else dp[u][0] = dp[u][1] = dp[u][2] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (int c = 0; c < 3; ++c) {
            int sm = 0;
            for (int cc = 0; cc < 3; ++cc) {
                if (c == cc) continue;
                sm += dp[v][cc];
                sm %= MOD;
            }
            dp[u][c] *= sm;
            dp[u][c] %= MOD;
        }
    }
}

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(color, -1, sizeof color);
    for (int i = 1; i <= k; ++i) {
        int u, c; cin >> u >> c;
        color[u] = --c;
    }
    dfs(1, 0);
    int ans = 0;
    for (int c = 0; c < 3; ++c) ans += dp[1][c], ans %= MOD;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
