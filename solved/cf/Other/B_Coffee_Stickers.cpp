#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n, m;
int u, v;
map<int, vector<int>> adj;
vector<int> ans;

void dfs(int u) {
    for (int c = 1; c < 5; ++c){
        int ok = 1;
        for (int v : adj[u]) {
            if (ans[v] == c) {
                ok = 0;
                break;
            }
        }
        if (!ok) continue;
        ans[u] = c;
        if (u + 1 > n) return;
        dfs(u + 1);
        if (ans[n] != -1) return;
        ans[u] = -1;
    }
}

void solve() {
    cin >> n >> m;
    ans.resize(n + 1, -1);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(all(adj[i]));
    }

    for (int i = 1; i <= n; i++) {
        if (ans[i] == -1) {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
