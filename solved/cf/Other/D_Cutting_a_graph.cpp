#include <bits/stdc++.h>
using namespace std;

struct Query {
    string type;
    int u, v;
};

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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
    }

    vector<Query> query(k);
    for (int i = 0; i < k; i++) {
        cin >> query[i].type >> query[i].u >> query[i].v;
    }
    reverse(query.begin(), query.end());
    DSU dsu(n);
    vector<string> results;
    for (auto &q : query) {
        if (q.type == "cut") {
            dsu.unite(q.u, q.v);
        } else {
            string res = "NO";
            if (dsu.find(q.u) == dsu.find(q.v)) res = "YES";
            results.push_back(res);
        }
    }
    reverse(results.begin(), results.end());
    for (const string &res : results) {
        cout << res << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);    
    solve();
}