#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

#include <bits/stdc++.h>
using namespace std;

// Weighted DSU: Slower, keeps tree structure for point inheritance.
struct Weighted_DSU {
    vector<int> parent, sz, val;
    Weighted_DSU(int n) { // O(n)
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        val.assign(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) { // O(log n)
        if (parent[u] == u) return u;
        return find(parent[u]);
    }
    void join_sets(int u, int v) { // O(log n)
        u = find(u), v = find(v);
        if (u != v) {
            if (sz[u] < sz[v]) swap(u, v);
            parent[v] = u;
            sz[u] += sz[v];
            val[v] -= val[u];
        }
    }
    void add_to_set(int u, int x) { // O(log n)
        val[find(u)] += x;
    }
    int get_value(int u) { // O(log n) 
        if (parent[u] == u) return val[u];
        return val[u] + get_value(parent[u]);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    Weighted_DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            dsu.add_to_set(u, 1);
            dsu.join_sets(u, v);
        }else {
            int u; cin >> u;
            cout << dsu.get_value(u) << endl;
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
