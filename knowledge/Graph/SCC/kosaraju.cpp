#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<int> adj[N], radj[N];
vector<int> order, comp;
bool vis[N];
int n, m;
vector<vector<int>> SCCs;

void dfs1(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs1(v);
    }
    order.push_back(u);
}

void dfs2(int u) {
    vis[u] = true;
    comp.push_back(u);
    for (int v : radj[u]) {
        if (!vis[v]) dfs2(v);
    }
}

void kosaraju() {
    for (int i = 1; i <= n; i++) vis[i] = false;
    order.clear();
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs1(i);
    }

    for (int i = 1; i <= n; i++) vis[i] = false;
    for (int i = n - 1; i >= 0; i--) {
        int u = order[i];
        if (!vis[u]) {
            comp.clear();
            dfs2(u);
            SCCs.push_back(comp);
        }
    }
}

void solve() {
    cin >> n >> m;
    SCCs.clear();
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        radj[i].clear();
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    kosaraju();
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}