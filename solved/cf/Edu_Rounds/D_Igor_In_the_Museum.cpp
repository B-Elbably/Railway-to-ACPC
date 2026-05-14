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
int id(int i, int j) {
    return i * 1000 + j;
};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int N = 1e6 + 5;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> grid(n, vector<char>(m));
    // vector<vector<int>> ans(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<int> ans(N, 0);
    DSU dsu(N);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') continue;
            for (int d = 0; d < 4; d++) {
                int x = i + dx[d], y = j + dy[d];
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    if (grid[x][y] == '.') {
                        dsu.unite(id(i,j), id(x,y));
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') continue;
            int u = dsu.find(id(i,j));
            for (int d = 0; d < 4; d++) {
                int x = i + dx[d], y = j + dy[d];
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    if (grid[x][y] == '.') continue;
                    ans[u]++;    
                }
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if (grid[i][j] == '*') continue;
    //         int u = dsu.find(id(i,j));
    //         ans[u] += ans[id(i,j)];
    //     }
    // }
    while (k--) {
        int x, y;
        cin >> x >> y;
        int u = dsu.find(id(--x, --y));
        cout << ans[u] << endl;
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
