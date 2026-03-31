#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    vector<int> mn, mx;
    DSU(int n) { // O(n)
        parent.resize(n + 1);
        mn.resize(n + 1);
        mx.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
        iota(mn.begin(), mn.end(), 0);
        iota(mx.begin(), mx.end(), 0);
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
            mn[pu] = min(mn[pu], mn[pv]);
            mx[pu] = max(mx[pu], mx[pv]);
        }
    }
    void get(int u) {
        int pu = find(u);
        cout << mn[pu] << " " << mx[pu] << " " << sz[pu] << endl;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    DSU dsu(n + 1);
    while (q--) {
        string t;
        int u, v;
        cin >> t;
        if (t == "union") {
            cin >> u >> v; 
            dsu.unite(u, v);
        } else {
            cin >> u;
            dsu.get(u);
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
