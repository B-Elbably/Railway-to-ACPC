#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MAXN = 2e5 + 5;
const int LOG = 20;

vector<int> adj[MAXN];
int succ[MAXN][LOG];

void dfs(int u, int p) {
    succ[u][0] = p;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}

void build(int n, int root) {
    dfs(root, 0);
    for (int i = 1; i < LOG; ++i) {
        for (int j = 1; j <= n; ++j) {
            succ[j][i] = succ[succ[j][i - 1]][i - 1];
        }
    }
}

int get_succ(int x, int k) {
    for (int p = 0; p < LOG; ++p) {
        if ((k >> p) & 1) {
            x = succ[x][p];
        }
    }
    return x == 0 ? -1 : x;
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i <= n; ++i) {
        adj[i].clear();
        for (int j = 0; j < LOG; ++j) {
            succ[i][j] = 0;
        }
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    build(n, 1);

    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << get_succ(x, k) << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}