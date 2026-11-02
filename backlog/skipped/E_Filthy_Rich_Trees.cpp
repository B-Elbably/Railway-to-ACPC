#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<double> tree;
    BIT(int n) : n(n), tree(n + 1, 0.0) {}
    void update(int i, double delta) {
        for (++i; i <= n; i += i & -i) tree[i] += delta;
    }
    double query(int i) {
        double sum = 0;
        for (++i; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
    double query(int l, int r) {
        return query(r - 1) - query(l - 1);
    }
};

struct EulerTour {
    int n, timer;
    vector<int> tin, tout;
    vector<double> current_vals;
    BIT bit;

    EulerTour(int n, const vector<vector<int>>& adj, int root = 1) 
        : n(n), timer(0), tin(n + 1), tout(n + 1), current_vals(n + 1, 0.0), bit(n) {
        dfs(root, 0, adj);
    }

    void dfs(int u, int p, const vector<vector<int>>& adj) {
        tin[u] = timer++;
        for (int v : adj[u]) {
            if (v != p) dfs(v, u, adj);
        }
        tout[u] = timer;
    }

    void update(int u, double new_val) {
        double delta = new_val - current_vals[u];
        current_vals[u] = new_val;
        bit.update(tin[u], delta);
    }

    double query_subtree(int u) {
        return bit.query(tin[u], tout[u]);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    EulerTour et(n, adj);
    int q;
    cin >> q;
    cout << fixed << setprecision(10);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u; double x;
            cin >> u >> x;
            et.update(u, log(x));
        } else {
            int x, y;
            cin >> x >> y;
            double diff = et.query_subtree(x) - et.query_subtree(y);
            if (diff >= 21.0) {
                cout << 1000000000.0 << "\n";
            } else {
                double ans = exp(diff);
                if (ans >= 1e9) cout << 1000000000.0 << "\n";
                else cout << ans << "\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}