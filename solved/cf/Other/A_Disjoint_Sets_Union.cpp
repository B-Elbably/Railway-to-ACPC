#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    DSU(int n) { // O(n) 
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) { // O(alpha(n)) amortized
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }
    void unite(int u, int v) { // O(alpha(n))
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            if (sz[pu] < sz[pv]) swap(pu, pv);
            parent[pv] = pu;
            sz[pu] += sz[pv];
        }
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    DSU dsu(n + 1);
    while (q--) {
        string t;
        int u, v;
        cin >> t >> u >> v;
        if (t == "union") {
            dsu.unite(u, v);
        } else {
            cout << (dsu.find(u) == dsu.find(v) ? "YES" : "NO") << endl;
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
