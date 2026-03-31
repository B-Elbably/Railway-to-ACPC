#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 300005;
const int LOG = 20;

vector<int> adj[MAX_N];
int up[MAX_N][LOG];
int d[MAX_N];

void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < LOG; i++) {
        up[u][i] = up[ up[u][i - 1] ][i - 1];
    }

    for (int v : adj[u]) {
        if (v == p) continue;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

int lift(int u, int k) {
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            u = up[u][i];
        }
    }
    return u;
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    u = lift(u, d[u] - d[v]);
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int dist(int u, int v) {
    int w = lca(u, v);
    return d[u] + d[v] - 2 * d[w];
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 1);
    int q; cin >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        int anc = lca(a, b);
        int d1 = dist(a, anc);
        int d2 = dist(b, anc);
        if (d1 > c) {
            cout << lift(a, c) << '\n';
            continue;
        }
        c -= d1;
        if (d2 > c) {
            cout << lift(b, d2 - c) << '\n';
            continue;
        }
        cout << b << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}