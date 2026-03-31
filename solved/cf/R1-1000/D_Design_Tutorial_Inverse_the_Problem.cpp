#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct DSU {
    vector<int> parent, sz;
    DSU(int n) { // O(n)
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) { // O(alpha(n)) - Path compression
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    bool unite(int u, int v) { // O(alpha(n)) - Union by size
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
struct Edge
{
    int u, v, w;
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (i == j) {
                if (grid[i][j] != 0) {
                    cout << "NO" << endl;
                    return;
                }
                continue;
            }

            if (i > j) {
                if (grid[i][j] != grid[j][i]) {
                cout << "NO" << endl;
                return;
                }
            } else {
                if (grid[i][j] == 0) {
                    cout << "NO" << endl;
                    return;
                }
                edges.push_back({i + 1, j + 1, grid[i][j]});
            }
        }
    }
    sort(all(edges), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });
    DSU dsu(n);
    vector<Edge> graph;
    for (auto& [u, v, w] : edges) {
        if (dsu.unite(u, v)) {
            graph.push_back({u, v, w});
        }
    }
    if ((int)graph.size() != n - 1) {
        cout << "NO" << endl;
        return;
    }

    vector<vector<pair<int, int>>> tree(n + 1);
    for (auto& [u, v, w] : graph) {
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }

    vector<int> dist(n + 1, -1);
    for (int s = 1; s <= n; s++) {
        fill(all(dist), -1);
        queue<int> q;
        q.push(s);
        dist[s] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& [v, w] : tree[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + w;
                    q.push(v);
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            if (dist[j] != grid[s - 1][j - 1]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
