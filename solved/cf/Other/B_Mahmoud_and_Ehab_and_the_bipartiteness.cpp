#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    set<pair<int, int>> edges;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> side(n + 1, -1);
    queue<int> q;
    q.push(1);
    side[1] = 0;
    int ones = 0, zeros = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (side[v] == -1) {
                side[v] = side[u] ^ 1;
                q.push(v);
                if (side[v]) ones++;
                else zeros++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (side[i]) ans += zeros;
        else ans += ones;
        ans -= adj[i].size();
    }
    cout << ans / 2 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
