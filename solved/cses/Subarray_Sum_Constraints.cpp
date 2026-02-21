#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int n, m;
vector<vector<array<int, 2>>> adj;
vector<int> pre;
vector<bool> vis;

void dfs(int u) {
    vis[u] = true;
    // cout << "[DFS] Visiting node " << u << ", pre[u] = " << pre[u] << endl;

    for (auto &[v, w] : adj[u]) {
        // cout << "  [Edge] " << u << " -> " << v << " with weight " << w << endl;

        if (vis[v]) {
            // cout << "    Node " << v << " already visited, pre[v] = " << pre[v] << endl;
            if (pre[v] != pre[u] + w) {
                // cout << "[Conflict] pre[" << v << "] != pre[" << u << "] + " << w << " => NO\n";
                cout << "NO\n";
                exit(0);
            } else {
                // cout << "    Edge consistent, continuing.\n";
            }
        } else {
            pre[v] = pre[u] + w;
            // cout << "    Setting pre[" << v << "] = " << pre[v] << " and DFS into node " << v << endl;
            dfs(v);
        }
    }
}

void solve() {
    cin >> n >> m;
    adj.assign(n + 1, {});
    pre.assign(n + 1, 0);
    vis.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int l, r, s;
        cin >> l >> r >> s;
        l--;
        adj[l].push_back({r, s});
        adj[r].push_back({l, -s});
    }

    for (int i = 0; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        // cout << pre[i] /*- pre[i - 1]*/ << (i == n ? '\n' : ' ');
        cout << pre[i] - pre[i - 1] << (i == n ? '\n' : ' ');
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}