#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int vis[MAXN], out[MAXN], timer;
vector<pair<int, int>> res;

void dfs(int u, int p) {
    vis[u] = ++timer;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (vis[v]) { // 
            if (vis[u] < vis[v]) {
                res.push_back({u, v});
                out[u]++;
            }
        } else {
            dfs(v, u);
            if (out[v] % 2) { 
                res.push_back({v, u});
                out[v]++;
            } else {
                res.push_back({u, v});
                out[u]++;
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 0);
            if (out[i] % 2) {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }

    for (auto &p : res) cout << p.first << " " << p.second << endl;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}


