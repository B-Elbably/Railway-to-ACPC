#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 505;
vector<int> adj[N];
int vis[N];
int mt[N];

bool dfs(int u) {
    for (int v: adj[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        if (!mt[v] || dfs(mt[v])) {
            mt[v] = u;
            return true;
        }
    }  
    return false;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i)) ans++;
    }
    cout << ans << endl;
    for (int i = 1; i <= m; i++) {
        if (mt[i]) cout << mt[i] << " " << i << endl;
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
