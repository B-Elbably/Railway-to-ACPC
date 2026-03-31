#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<long long> tree;
    BIT(int n) : n(n), tree(n + 1, 0) {}
    void update(int i, long long delta) {
        for (++i; i <= n; i += i & -i) tree[i] += delta;
    }
    long long query(int i) {
        long long sum = 0;
        for (++i; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
    long long query(int l, int r) {
        return query(r - 1) - query(l - 1);
    }
};

struct EulerTour {
    int n, timer;
    vector<int> tin, tout;
    vector<long long> current_vals;
    BIT bit;

    EulerTour(int n, const vector<long long>& v, const vector<vector<int>>& adj, int root = 1) 
        : n(n), timer(0), tin(n + 1), tout(n + 1), current_vals(n + 1), bit(n) {
        dfs(root, 0, adj);
        for (int i = 1; i <= n; i++) {
            current_vals[i] = v[i];
            bit.update(tin[i], v[i]);
        }
    }

    void dfs(int u, int p, const vector<vector<int>>& adj) {
        tin[u] = timer++;
        for (int v : adj[u]) {
            if (v != p) dfs(v, u, adj);
        }
        tout[u] = timer;
    }

    void update(int u, long long new_val) {
        long long delta = new_val - current_vals[u];
        current_vals[u] = new_val;
        bit.update(tin[u], delta);
    }

    long long query_subtree(int u) {
        return bit.query(tin[u], tout[u]);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> vals(n + 1);
    for (int i = 1; i <= n; i++) cin >> vals[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    EulerTour et(n, vals, adj);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u;
            long long x;
            cin >> u >> x;
            et.update(u, x);
        } else {
            int u;
            cin >> u;
            cout << et.query_subtree(u) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}