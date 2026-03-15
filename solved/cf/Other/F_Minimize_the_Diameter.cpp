#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 2e5 + 5;
int vis[N*2];
vector<vector<int>> adj(N*2);

pair<int, int> dfs(int u, int p = -1) {
    vis[u] = 1;
    pair<int, int> res = {0, u};
    for (int v : adj[u]) {
        if (v == p) continue;
        if (!vis[v]) {
            auto tmp = dfs(v, u);
            tmp.first++;
            res = max(res, tmp);
        }
    }
    return res;
}

int solve(int shift = 0) {
    int n; cin >> n;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        u += shift;
        v += shift;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto[_, b] = dfs(1 + shift);
    memset(vis, 0, sizeof(vis));
    auto[dist, __] = dfs(b);
    return dist;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans1 = solve();
    int ans2 = solve(N);
    cout << max({ans1, ans2, (ans1 + 1) / 2 + 1 + (ans2 + 1) / 2}) << endl;
}