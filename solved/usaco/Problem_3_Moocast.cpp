#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> points(n + 1);
    for (int i = 1; i <= n; i++) {
        int x, y, radius;
        cin >> x >> y >> radius;
        points[i] = {x, y, radius};
    }
    for (int u = 1; u <= n; ++u){
        for (int v = 1; v <= n; ++v){
            if (u == v) continue;
            int dx = points[u][0] - points[v][0];
            int dy = points[u][1] - points[v][1];
            if (dx * dx + dy * dy <= points[u][2] * points[u][2]) {
                adj[u].push_back(v);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(i);
        visited[i] = true;
        int res = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            res++;
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
