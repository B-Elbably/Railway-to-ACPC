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
    int n; cin >> n;
    int ans = 0;
    for (int p = 1; p < n; p *= 2) {
        int cnt = (n + p - 1) / (p * 2);
        ans += cnt * p;
    }
    cout << ans << "\n";
}

// void solve() {
//     int n;
//     cin >> n;
//     vector<Edge> edges;
//     // for (int i = 0; i < m; i++) 
//     //     cin >> edges[i].u >> edges[i].v >> edges[i].w;
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             if (i == j) continue;
//             edges.push_back({i, j, (i ^ j)});
//             edges.push_back({j, i, (i ^ j)});
//         }
//     }
//     sort(edges.begin(), edges.end());
//     DSU dsu(n);
//     int ans = 0;
//     vector<Edge> mst_edges;

//     for (auto &e : edges) {
//         if (dsu.unite(e.u, e.v)) {
//             ans += e.w;
//             mst_edges.push_back(e);
//         }
//     }

//     cout << ans << "\n";
//     // for (auto &e : mst_edges) cout << e.u << " " << e.v << " " << e.w << "\n";
//     // for (auto &e : mst_edges) cout << e.w << " ";

// }

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
// -
// 2 -> 1 = 1                                   | 1 * 1
// 3 -> 1 2 = 3                                 | 1 * 1 + 2 * 1
// 4 -> 1 1 2 = 4                               | 1 * 2 + 2 * 1
// 5 -> 1 1 2 4 = 8                             | 1 * 2 + 2 * 1 + 4 * 1
// 6 -> 1 1 1 2 4 = 9                           | 1 * 3 + 2 * 1 + 4 * 1
// 7 -> 1 1 1 2 2 4 = 11                        | 1 * 3 + 2 * 2 + 4 * 1
// 8 -> 1 1 1 1 2 2 4 = 12                      | 1 * 4 + 2 * 2 + 4 * 1
// 9 -> 1 1 1 1 2 2 4 8 = 20                    | 1 * 4 + 2 * 2 + 4 * 1 + 8 * 1
// 10-> 1 1 1 1 1 2 2 4 8 = 21                  | 1 * 5 + 2 * 2 + 4 * 1 + 8 * 1
// 11-> 1 1 1 1 1 2 2 2 4 8 = 23                | 1 * 5 + 2 * 3 + 4 * 1 + 8 * 1
// 12-> 1 1 1 1 1 1 2 2 2 4 8 = 24              | 1 * 6 + 2 * 3 + 4 * 1 + 8 * 1
// 13-> 1 1 1 1 1 1 2 2 2 4 4 8 = 28            | 1 * 6 + 2 * 3 + 4 * 2 + 8 * 1
// 14-> 1 1 1 1 1 1 1 2 2 2 4 4 8 = 29          | 1 * 7 + 2 * 3 + 4 * 2 + 8 * 1
// 15-> 1 1 1 1 1 1 1 2 2 2 2 4 4 8 = 31        | 1 * 7 + 2 * 4 + 4 * 2 + 8 * 1
// 16-> 1 1 1 1 1 1 1 1 2 2 2 2 4 4 8 = 32      | 1 * 8 + 2 * 4 + 4 * 2 + 8 * 1
// 17-> 1 1 1 1 1 1 1 1 2 2 2 2 4 4 8 16 = 48   | 1 * 8 + 2 * 4 + 4 * 2 + 8 * 1 + 16 * 1
