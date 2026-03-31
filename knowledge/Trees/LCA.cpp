#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 200005;
const int LOG = 20;

vector<int> adj[MAX_N];
int up[MAX_N][LOG];
int d[MAX_N];

void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < LOG; i++) {
        up[u][i] = up[ up[u][i - 1] ][i - 1];
    }

    for (int v : adj[u]) {
        if (v == p) continue;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

int lift(int u, int k) {
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            u = up[u][i];
        }
    }
    return u;
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    u = lift(u, d[u] - d[v]);
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int dist(int u, int v) {
    int w = lca(u, v);
    return d[u] + d[v] - 2 * d[w];
}

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    dfs(1, 1);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) { // LCA query
            int u, v;
            cin >> u >> v;
            cout << lca(u, v) << '\n';
        } 
        else if (type == 2) { // Distance query
            int u, v;
            cin >> u >> v;
            cout << dist(u, v) << '\n';
        } 
        else if (type == 3) { // K-th ancestor query
            int u, k;
            cin >> u >> k;
            if (d[u] < k) cout << -1 << '\n';
            else cout << lift(u, k) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}