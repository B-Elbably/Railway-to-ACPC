#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 200005;
vector<int> adj[N];
int deg[N];
int pos[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        deg[i] = 0;
    }
    
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        edges.push_back({u, v});
        if (t == 1) {
            adj[u].push_back(v);
            deg[v]++;
        }
    }

    queue<int> q; 
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        pos[u] = cnt++;

        for (int v : adj[u]) {
            deg[v]--;
            if (deg[v] == 0) {
                q.push(v);
            }
        }
    }

    if (cnt < n) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (auto e : edges) {
            if (pos[e.first] < pos[e.second]) {
                cout << e.first << " " << e.second << endl;
            } else {
                cout << e.second << " " << e.first << endl;
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}