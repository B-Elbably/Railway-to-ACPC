#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e4 + 5;
int vis[N + 1];
vector<vector<int>> adj(N + 1);

void dfs(int u, int p = -1) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (!vis[v]) dfs(v);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int j; cin >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs(i);
        ans++;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
