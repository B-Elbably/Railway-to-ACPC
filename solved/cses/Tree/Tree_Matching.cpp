#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
vector<int> adj[200005];
int ans = 0;
int vis[200005];

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (vis[u] == 0 && vis[v] == 0) {
            ans++;
            vis[u] = vis[v] = 1;
        }
    }
    
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {   
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
