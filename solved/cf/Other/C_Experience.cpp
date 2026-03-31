#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    vector<int> ans;
    DSU(int n) { // O(n)
        parent.resize(n + 1);
        ans.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) { // O(alpha(n)) amortized
        if (parent[u] == u)
            return u;
        return find(parent[u]);
    }
    void unite(int u, int v) { // O(alpha(n))
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            if (sz[pu] < sz[pv]) swap(pu, pv);
            parent[pv] = pu;
            sz[pu] += sz[pv];
            ans[pv] -= ans[pu];
        }
    }
    void add(int u, int x) {
        ans[find(u)] += x;
    }
    int get(int u) {
        if (parent[u] == u) {
            return ans[u];
        } else {
            return get(parent[u]) + ans[u];
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
        cin >> t;
        if (t == "add") {
            cin >> u >> v;
            dsu.add(u, v);
        }else if (t == "get") {
            cin >> u;
            cout << dsu.get(u) << endl;
        } else {
            cin >> u >> v;
            dsu.unite(u, v);
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
