#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n; 
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }

    if (*max_element(all(deg)) > 3) {
        cout << "NO\n";
        return;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        deg[u]--;
        for (int v : adj[u]) {
            if (deg[v] == 0) continue;
            deg[v]--;
            if (deg[v] == 1 && adj[v].size() != 3) {
                q.push(v);
            }
        }
    }
    string ans = *max_element(all(deg)) < 3 ? "YES" : "NO";
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t; 
    while (t--) solve();
}

/*

1
10
1 2
1 3
1 4
2 5
2 6
3 7
3 8
4 9
4 10

NO
*/