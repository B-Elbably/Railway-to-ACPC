#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
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
    int target = (zeros > ones ? 1 : 0);
    vector<int> ans;
    for (int i = 1; i <= n; i++) 
        if (side[i] == target) ans.push_back(i);
    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
