#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 1e5 + 5;
vector<int> adj[N], best[N][20], people[N];
int depth[N], parent[N], up[N][20]; 

vector<int> merge(vector<int> a, vector<int> b) {
    vector<int> c;
    int i = 0, j = 0;
    while ((i < a.size() || j < b.size()) && c.size() < 10) {
        if (i < a.size() && (j == b.size() || a[i] < b[j])) c.push_back(a[i++]);
        else c.push_back(b[j++]);
    }
    return c;
}

void dfs(int u, int p) {
    depth[u] = depth[p] + 1;
    best[u][0] = people[u];
    up[u][0] = p;
    parent[u] = p;
    for (int i = 1; i < 20; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
        best[u][i] = merge(best[u][i - 1], best[up[u][i - 1]][i - 1]);
    }   
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 19; i >= 0; i--) {
        if (depth[up[u][i]] >= depth[v]) u = up[u][i];
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return parent[u];
}

int kth(int u, int k) {
    for (int i = 19; i >= 0; i--) {
        if (k >= (1 << i)) {
            u = up[u][i];
            k -= (1 << i);
        }
    }
    return u;
}

vector<int> query(int u, int v) {
    vector<int> res;
    int d = depth[u] - depth[v];
    for (int i = 19; i >= 0; i--) {
        if ((d >> i) & 1) {
            res = merge(res, best[u][i]);
            u = up[u][i];
        }
    }
    return res;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        if (people[x].size() < 10) people[x].push_back(i);
    }
    depth[0] = -1;
    dfs(1, 0);
    while (q--) {
        int u, v, a;
        cin >> u >> v >> a;
        int w = lca(u, v);
        vector<int> res = merge(query(u, w), query(v, w));
        res = merge(res, people[w]);
        if (res.size() > a) res.resize(a);
        cout << res.size() << " ";
        for (int x : res) cout << x << " ";
        cout << endl;
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
