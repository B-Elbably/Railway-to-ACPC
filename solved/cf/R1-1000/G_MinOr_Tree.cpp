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
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end());
    // DSU dsu(n);
    // for (auto &e : edges) {
        //     dsu.unite(e.u, e.v);
        // }
    int ans = (1 << 30) - 1;
    for (int i = 29; i >= 0; --i) {
        int mask = ans ^ (1 << i);
        int N = n;
        DSU dsu(n);
        for (auto &e : edges) {
            if ((e.w | mask) == mask) {
                if (dsu.unite(e.u, e.v)) {
                    N--;
                }
            }
        }
        if (N == 1) {
            ans = mask;
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
