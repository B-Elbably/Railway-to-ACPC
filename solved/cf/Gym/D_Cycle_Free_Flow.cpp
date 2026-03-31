// LCA with path queries (max on path)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct LCA {
    int n, LOG;
    ll SKIP;
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<vector<ll>> st;
    vector<ll> val;
    vector<int> d;

    LCA(int n) : n(n), LOG(ceil(log2(n + 1)) + 1), SKIP(1e18), 
                adj(n + 1), up(n + 1, vector<int>(LOG)), 
                st(n + 1, vector<ll>(LOG)), val(n + 1), d(n + 1) {}

    ll merge(ll a, ll b) {
        return min(a, b);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int p) {
        up[u][0] = p;
        st[u][0] = val[u];
        
        for (int i = 1; i < LOG; i++) {
            up[u][i] = up[ up[u][i - 1] ][i - 1];
            st[u][i] = merge(st[u][i - 1], st[ up[u][i - 1] ][i - 1]);
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

    ll query(int u, int anc) {
        ll res = SKIP;
        int diff = d[u] - d[anc];
        for (int i = 0; i < LOG; i++) {
            if (diff & (1 << i)) {
                res = merge(res, st[u][i]);
                u = up[u][i];
            }
        }
        return res;
    }

    ll path(int u, int v) {
        int anc = lca(u, v);
        ll res_u = query(u, anc);   
        ll res_v = query(v, anc);
        
        return merge(res_u, res_v);
    }
};
struct Edge {
    int u, v, w;
};
void solve() {
    int n, m;
    cin >> n >> m;
    LCA tree(n);

    vector<Edge> edges(m);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        tree.add_edge(u, v);
        edges[i - 1] = {u, v, w};
    }

    tree.dfs(1, 1);
    for (const auto &e : edges) {
        if (tree.lca(e.u, e.v) == e.u) {
            tree.val[e.v] = e.w;
        } else {
            tree.val[e.u] = e.w;
        }
    }
    tree.dfs(1, 1);
    int q; cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << tree.path(u, v) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}