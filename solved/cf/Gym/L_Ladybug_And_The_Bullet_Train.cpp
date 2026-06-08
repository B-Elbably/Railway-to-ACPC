#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 1e6 + 5;
vector<int> adj[N];
int sz[N], dep[N], par[N];
int counter;
int pp = -1;
void dfs(int u, int p, int d) {
    sz[u] = 1;
    dep[u] = d;
    par[u] = p;
    for (int v : adj[u]) {
        if (v == p || v == pp) continue;
        dfs(v, u, d + 1);
        sz[u] += sz[v];
    }
}

void solve() {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
    if (par[x] == 1) {
        cout << 1;
        return;
    }
    // counter = 0;
    // for (int i = 1; i <= n; ++i) cout << sz[i] << " ";
    // cout << endl;
    adj[par[x]].clear();
    pp = par[x];
    int ppp = par[par[x]];
    int xxx = dep[x];
    memset(sz, 0, sizeof(sz));
    memset(dep, 0, sizeof(dep));
    memset(par, 0, sizeof(par));
    // for (int i = 1; i <= n; ++i) {
    //     if (i == x) adj[i].clear();
    //     adj[i].erase(remove(all(adj[i]), par[x]), adj[i].end());
    // }

    dfs(1, 0, 0);
    int ans = (sz[1] - 1) * 2 + 3;
    // for (int i = 1; i <= n; ++i) cout << sz[i] << " ";
    // while (ppp != 1) {
    //     ans--;
    //     ppp = par[ppp];
    // }
    cout << ans - (xxx - 1) << endl;
    // cout << counter;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
