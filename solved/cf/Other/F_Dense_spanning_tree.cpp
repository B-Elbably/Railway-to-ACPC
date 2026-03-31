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

void solve() {
    int n, m;
    cin >> n >> m;
    
    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    vector<pair<int, pair<int, int>>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, {u, v}};
    }
    sort(all(edges));

    int ans = 2e18;
    for (int i = 0; i + n - 1 <= m; i++) {
        DSU dsu(n);
        int comps = n;
        for (int j = i; j < m; j++) {
            int u = edges[j].second.first;
            int v = edges[j].second.second;
            if (!dsu.unite(u, v)) continue;
            if (--comps == 1) {
                ans = min(ans, edges[j].first - edges[i].first);
                break;
            }
        }
    }
    if (ans == 2e18) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << ans << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}