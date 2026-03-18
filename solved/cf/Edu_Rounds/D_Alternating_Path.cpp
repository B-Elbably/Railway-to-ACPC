#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 2e5 + 5;
vector<int> adj[N];
int side[N];
bool is_bipartite;
int c0, c1;

void dfs(int u, int s) {
    side[u] = s;
    if (s == 0) c0++;
    else c1++;
    for (int v : adj[u]) {
        if (side[v] == s)
            is_bipartite = false;
        else if (side[v] == -1)
            dfs(v, 1 - s);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        side[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (~side[i]) continue;
        is_bipartite = true;
        c0 = c1 = 0;
        dfs(i, 0);
        if (!is_bipartite) continue;
        ans += max(c0, c1);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}