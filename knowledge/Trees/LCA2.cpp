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

    LCA(int n) : n(n), LOG(ceil(log2(n + 1)) + 1), SKIP(-1e18), 
                adj(n + 1), up(n + 1, vector<int>(LOG)), 
                st(n + 1, vector<ll>(LOG)), val(n + 1), d(n + 1) {}

    ll merge(ll a, ll b) {
        return max(a, b);
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
        
        return merge(merge(res_u, res_v), val[anc]);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    LCA tree(n);

    for (int i = 1; i <= n; i++) {
        cin >> tree.val[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree.add_edge(u, v);
    }

    tree.dfs(1, 1);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            cout << tree.lca(u, v) << '\n';
        } 
        else if (type == 2) {
            int u, v;
            cin >> u >> v;
            cout << tree.dist(u, v) << '\n';
        } 
        else if (type == 3) {
            int u, k;
            cin >> u >> k;
            if (tree.d[u] < k) cout << -1 << '\n';
            else cout << tree.lift(u, k) << '\n';
        }
        else if (type == 4) {
            int u, v;
            cin >> u >> v;
            cout << tree.path(u, v) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}