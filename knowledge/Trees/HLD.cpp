#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Fenwick {
    int n;
    vector<ll> tree;

    Fenwick(int n) : n(n), tree(n + 1, 0) {}

    void update(int i, ll delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }

    ll query(int i) {
        ll sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }

    ll query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

struct HLD {
    int n, timer;
    vector<vector<int>> adj;
    vector<int> parent, depth, sz, head, pos;
    vector<ll> val;
    Fenwick bit;

    HLD(int n) : n(n), timer(1), adj(n + 1), parent(n + 1), 
                 depth(n + 1), sz(n + 1), head(n + 1), pos(n + 1), 
                 val(n + 1), bit(n) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs_sz(int u, int p, int d) {
        sz[u] = 1;
        parent[u] = p;
        depth[u] = d;
        if (adj[u].size() > 1 && adj[u][0] == p) swap(adj[u][0], adj[u].back());
        for (int &v : adj[u]) {
            if (v == p) continue;
            dfs_sz(v, u, d + 1);
            sz[u] += sz[v];
            if (sz[v] > sz[adj[u][0]]) swap(v, adj[u][0]);
        }
    }

    void dfs_hld(int u, int p, int h) {
        head[u] = h;
        pos[u] = timer++;
        for (int v : adj[u]) {
            if (v == p) continue;
            dfs_hld(v, u, (v == adj[u][0] ? h : v));
        }
    }

    void build() {
        dfs_sz(1, 1, 0);
        dfs_hld(1, 1, 1);
        for (int i = 1; i <= n; i++) {
            bit.update(pos[i], val[i]);
        }
    }

    void update(int u, ll v) {
        ll current_val = bit.query(pos[u], pos[u]);
        bit.update(pos[u], v - current_val);
        val[u] = v;
    }

    ll query_path(int u, int v) {
        ll res = 0;
        for (; head[u] != head[v]; v = parent[head[v]]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            res += bit.query(pos[head[v]], pos[v]);
        }
        if (depth[u] > depth[v]) swap(u, v);
        res += bit.query(pos[u], pos[v]);
        return res;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    HLD hld(n);
    for (int i = 1; i <= n; i++) {
        cin >> hld.val[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        hld.add_edge(u, v);
    }

    hld.build();
    while (q--) {
        int type;
        cin >> type;

        if (type == 1) { // Update value of node u
            int u;
            ll val;
            cin >> u >> val;
            hld.update(u, val);
        } 
        else if (type == 2) { // Query sum on path from u to v
            int u, v;
            cin >> u >> v;
            cout << hld.query_path(u, v) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}