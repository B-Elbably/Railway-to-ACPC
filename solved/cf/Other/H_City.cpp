#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct DSU {
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) {
            if (sz[u] < sz[v]) swap(u, v);
            parent[v] = u;
            sz[u] += sz[v];
            return true;
        }
        return false;
    }
};

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> b(m + 1);
    for (int i = 0; i < m; ++i) cin >> b[i];
    vector<Edge> edges;
    Edge e;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; ++j) {
            cin >> e.w;
            e.u = i;
            e.v = j;
            if (i == j) continue;
            edges.push_back(e);
        }
    }
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    for (int i = 0; i < m; ++i) {
        dsu.unite(b[i], b[i + 1]);
    }
    int ans = 0;
    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            ans += e.w;
        }
    }
    cout << ans << "\n";

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
