#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
struct pt {
    int x, y, z;
    bool operator==(const pt &other) const {
        return x == other.x && y == other.y && z == other.z;
    }
    bool operator<(const pt &other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }
};
const int N = 1e5 + 5;
vector<int> adj[N], vis(N);

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        vis[i] = 0;
    }
    
    vector<pair<pair<pt, pt>, int>> edges;
    for (int i = 0; i < n; ++i) {
        pt a, b, c;
        cin >> a.x >> a.y >> a.z;
        cin >> b.x >> b.y >> b.z;
        cin >> c.x >> c.y >> c.z;
        edges.push_back({{min(a, b), max(a, b)}, i});
        edges.push_back({{min(b, c), max(b, c)}, i});
        edges.push_back({{min(c, a), max(c, a)}, i});
    }
    sort(all(edges));
    for (int i = 0; i < edges.size() - 1; ++i) {
        if (edges[i].first == edges[i + 1].first) {
            adj[edges[i].second].push_back(edges[i + 1].second);
            adj[edges[i + 1].second].push_back(edges[i].second);
        }
    }
    dfs(0);
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("triangles.in", "r", stdin);
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
