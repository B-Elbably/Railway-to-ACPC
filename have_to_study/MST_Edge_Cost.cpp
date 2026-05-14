#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

const int MAX_N = 200005;
const int LOG = 20;

vector<pair<int, int>> adj[MAX_N];
int up[MAX_N][LOG];
int max_w[MAX_N][LOG];
int d[MAX_N];

void dfs(int u, int p, int edge_weight) {
    up[u][0] = p;
    max_w[u][0] = edge_weight;
    for (int i = 1; i < LOG; i++) {
        up[u][i] = up[ up[u][i - 1] ][i - 1];
        max_w[u][i] = max(max_w[u][i - 1], max_w[ up[u][i - 1] ][i - 1]);
    }

    for (auto& edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v == p) continue;
        d[v] = d[u] + 1;
        dfs(v, u, w);
    }
}

int query_max(int u, int v) {
    int mx = 0;
    if (d[u] < d[v]) swap(u, v);
    int diff = d[u] - d[v];
    for (int i = 0; i < LOG; i++) {
        if (diff & (1 << i)) {
            mx = max(mx, max_w[u][i]);
            u = up[u][i];
        }
    }
    if (u == v) return mx;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            mx = max({mx, max_w[u][i], max_w[v][i]});
            u = up[u][i];
            v = up[v][i];
        }
    }
    return max({mx, max_w[u][0], max_w[v][0]});
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].id = i;
    }

    vector<Edge> edges2 = edges;
    sort(edges2.begin(), edges2.end());

    DSU dsu(n);
    ll sum = 0;
    vector<bool> in_mst(m, false);

    for (auto &e : edges2) {
        if (dsu.unite(e.u, e.v)) {
            sum += e.w;
            in_mst[e.id] = true;
            adj[e.u].push_back({e.v, e.w});
            adj[e.v].push_back({e.u, e.w});
        }
    }

    dfs(1, 1, 0);

    for (int i = 0; i < m; i++) {
        if (in_mst[i]) {
            cout << sum << '\n';
        } else {
            cout << sum + edges[i].w - query_max(edges[i].u, edges[i].v) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}