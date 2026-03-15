#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<pair<int,int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u, v};
    }
    vector<int> side(n + 1, -1);
    queue<int> q;
    q.push(1);
    side[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (side[v] == -1) {
                side[v] = side[u] ^ 1;
                q.push(v);
            } else if (side[v] == side[u]) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
    string ans(m, '1');
    for (int i = 0; i < m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        if (side[u] > side[v]) ans[i] = '0';
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