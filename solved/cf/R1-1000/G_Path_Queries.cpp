#include <bits/stdc++.h>
using namespace std;
#define int long long

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
const int N = 2e5 + 5;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(n - 1);
    for (int i = 0; i < n - 1; i++) 
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    sort(edges.begin(), edges.end());
    DSU dsu(n);

    vector<int> ans(N);
    int j = 0;
    int res = 0;
    for (int i = 1; i <= N - 5; ++i) {
        while (j < n - 1 && edges[j].w <= i) {
            int u = dsu.find(edges[j].u);
            int v = dsu.find(edges[j].v);
            if (u != v) {
                res += 1LL * dsu.sz[u] * dsu.sz[v];
                dsu.unite(u, v);
            }
            ++j;
        }
        ans[i] = res;
    }
    while (m--) {
        int x;
        cin >> x;
        cout << ans[x] << " ";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
