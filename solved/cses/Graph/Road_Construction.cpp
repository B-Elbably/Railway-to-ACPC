#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int mx = 1;
struct DSU {
    vector<int> parent, sz;
    DSU(int n) { // O(n)
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) { // O(alpha(n))
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    bool unite(int u, int v) { // O(alpha(n))
        u = find(u), v = find(v);
        if (u != v) {
            if (sz[u] < sz[v]) swap(u, v);
            parent[v] = u;
            sz[u] += sz[v];
            mx = max(mx, sz[u]);
            return true;
        }
        return false;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    int comp = n;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        comp -= dsu.unite(u, v);
        cout << comp << " " << mx << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
