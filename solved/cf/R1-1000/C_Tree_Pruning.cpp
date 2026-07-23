#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> dep(n + 1, 0), path(n + 1, 0);
    function<void(int, int)> dfs;
    dfs = [&](int u, int p) -> void {
        path[u] = dep[u];
        for (int v : adj[u]) {
            if (v == p) continue;
            dep[v] = dep[u] + 1;
            dfs(v, u);
            path[u] = max(path[u], path[v]);
        }
    };
    dfs(1, 0);
    vector<int> cnt(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        cnt[dep[i]]++;
        cnt[path[i] + 1]--;
    }
    for (int i = 1; i <= n; ++i) cnt[i] += cnt[i - 1];
    cout << n - *max_element(all(cnt)) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}