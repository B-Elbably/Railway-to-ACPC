#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n, k;
const int N = 403;
vector<pair<int, int>> adj[N];
int dp[N][N];
int parent_edge[N];
int sz[N];
vector<int> cuts[N][N];

void dfs(int u, int p) {
    sz[u] = 1;
    dp[u][1] = 0;
    for (auto [v, id] : adj[u]) {
        if (v == p) continue;
        parent_edge[v] = id;
        dfs(v, u);
        int mx = min(k, sz[u] + sz[v]);
        for (int i = mx; i >= 1; i--) {
            int c = dp[u][i] + 1;
            vector<int> rmv = cuts[u][i];
            rmv.push_back(id);
            for (int j = 1; j < i && j <= sz[v]; j++) {
                if (dp[u][i - j] + dp[v][j] < c) {
                    c = dp[u][i - j] + dp[v][j];
                    rmv = cuts[u][i - j];
                    for (int x : cuts[v][j]) rmv.push_back(x);
                }
            }
            dp[u][i] = c;
            cuts[u][i] = rmv;
        }
        sz[u] += sz[v];
    }
};

void init() {
    for (int i = 1; i <= n; ++i) 
        for (int j = 0; j <= k; ++j) 
            dp[i][j] = 1e9;    
}

void solve() {
    cin >> n >> k;
    init();
    if (k == n) {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    dfs(1, 0);
    int ans = 1e9;
    vector<int> res;
    for (int i = 1; i <= n; ++i) {
        if (dp[i][k] == 1e9) continue;
        int c = dp[i][k] + (i > 1);
        if (c < ans) {
            ans = c;
            res = cuts[i][k];
            if (i - 1) 
                res.push_back(parent_edge[i]);
        }
    }
    cout << ans << endl;
    for (int x : res) cout << x << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
