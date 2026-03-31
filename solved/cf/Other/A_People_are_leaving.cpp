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
    void unite(int u, int v) { // O(alpha(n)) - Union by size
        // u = find(u), v = find(v);
        // if (u != v) {
        //     if (sz[u] < sz[v]) swap(u, v);
        //     parent[v] = u;
        //     sz[u] += sz[v];
        //     return true;
        // }
        // return false;
        parent[find(u)] = find(v);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    for (int i = 0; i < m; i++) {
        char type; int u;
        cin >> type >> u;
        if (type == '?') {
            int pu = dsu.find(u);
            if (pu > n) pu = -1;
            cout << pu << endl;
        }else {
            dsu.unite(u, u + 1);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
