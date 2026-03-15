#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MAXN = 1e5 + 5;
const int LOGN = 18;

vector<int> adj[MAXN];
int up[MAXN][LOGN], depth[MAXN], prefG[MAXN];
string breeds;

void dfs(int u, int p, int g) {
    depth[u] = depth[p] + 1;
    up[u][0] = p;
    prefG[u] = g + (breeds[u-1] == 'G');

    for (int i = 1; i < LOGN; i++) {
        up[u][i] = up[up[u][i-1]][i-1];
    }

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, prefG[u]);
    }
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOGN - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) u = up[u][i];
    }
    if (u == v) return u;
    for (int i = LOGN - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

void solve() {
    int n, m;
    cin >> n >> m;
    cin >> breeds;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 1, 0);
    vector<char> ans(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        int lca = LCA(a, b);
        int sum = prefG[a] + prefG[b] - 2 * prefG[lca] + (breeds[lca-1] == 'G');
        int nodes = depth[a] + depth[b] - 2 * depth[lca] + 1;
        
        if (c == 'G') {
            ans[i] = (sum > 0 ? '1' : '0');
        } else {
            ans[i] = (nodes > sum ? '1' : '0');
        }
    }
    for (char c : ans) cout << c;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}