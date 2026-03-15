#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, char>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        char c; cin >> c;
        int u, v; cin >> u >> v;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    vector<int> side(n + 1, -1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (side[i] == -1) {
            ans++; side[i] = 0;
            queue<int> q; q.push(i);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (auto &[v, type] : adj[u]) {
                    int side_ = (type == 'S' ? side[u] : side[u] ^ 1);
                    if (side[v] == -1) {
                        side[v] = side_;
                        q.push(v);
                    } 
                    else if (side[v] != side_) {
                        cout << 0 << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << 1;
    for (int i = 0; i < ans; i++) cout << 0;
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    solve();
}