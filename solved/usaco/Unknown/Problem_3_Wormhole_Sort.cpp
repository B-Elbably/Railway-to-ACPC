#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> edges(m);
    for (auto &x : edges) {
        int u, v, w;
        cin >> u >> v >> w;
        x = {w, u, v};
    }

    bool ok = true;
    for (int i = 1; i <= n; i++)
        if (a[i] != i) ok = false;
    if (ok) {
        cout << -1 << endl;
        return;
    }

    sort(all(edges));
    int l = 0, r = m - 1, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        vector<vector<int>> adj(n + 1);
        for (int i = mid; i < m; i++) {
            int w = edges[i][0], u = edges[i][1], v = edges[i][2];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n + 1, false);
        function<void(int)> dfs = [&](int u) {
            vis[u] = true;
            for (auto &v : adj[u])
                if (!vis[v])
                    dfs(v);
        };
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && a[i] != i) {
                dfs(i);
                break;
            }
        }
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && a[i] != i) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = edges[mid][0];
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    solve();
}