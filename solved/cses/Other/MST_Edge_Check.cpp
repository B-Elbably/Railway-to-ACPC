#include <bits/stdc++.h>
using namespace std;

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
    int u, v, w, id;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    vector<bool> ok(m, false);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].id = i;
    }
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    for (int i = 0; i < m; ) {
        int j = i;
        while (j < m && edges[j].w == edges[i].w) j++;
        for (int k = i; k < j; k++) {
            if (dsu.find(edges[k].u) != dsu.find(edges[k].v)) {
                ok[edges[k].id] = true;
            }
        }
        for (int k = i; k < j; k++) {
            dsu.unite(edges[k].u, edges[k].v);
        }
        i = j;
    }
    for (int i = 0; i < m; i++) {
        cout << (ok[i] ? "YES" : "NO") << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}