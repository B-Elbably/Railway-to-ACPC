#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
vector<pair<int, int>> adj[N];
vector<int> tree[N];
int tin[N], low[N], comp[N], timer, ncc;
bool is_bridge[N];
pair<int, int> edges[N];

void dfs(int u, int p = -1) {
    tin[u] = low[u] = ++timer;
    for (auto [v, id] : adj[u]) {
        if (id == p) continue;
        if (tin[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, id);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) is_bridge[id] = true;
        }
    }
}

void dfs2(int u) {
    comp[u] = ncc;
    for (auto [v, id] : adj[u]) {
        if (!comp[v] && !is_bridge[id]) dfs2(v);
    }
}

void build_bridge_tree(int n, int m) {
    timer = ncc = 0;
    for (int i = 1; i <= n; i++) {
        tin[i] = comp[i] = 0;
        tree[i].clear();
    }
    for (int i = 1; i <= m; i++) is_bridge[i] = false;
    
    for (int i = 1; i <= n; i++) {
        if (!tin[i]) dfs(i);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!comp[i]) {
            ++ncc;
            dfs2(i);
        }
    }
    
    for (int i = 1; i <= m; i++) {
        if (is_bridge[i]) {
            int u = comp[edges[i].first];
            int v = comp[edges[i].second];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
    }
}

int far, mx;
int vis[N], dist[N];
void dfs3(int u, int p, int d) {
    if (d > mx) {
        mx = d;
        far = u;
    }
    for (int v : tree[u]) {
        if (v != p) {
            dfs3(v, u, d + 1);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    // for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    build_bridge_tree(n, m);
    far = 0, mx = 0;
    dfs3(1, -1, 0);
    int start = far;
    far = 0, mx = 0;
    dfs3(start, -1, 0);
    cout << mx << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
