#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 2505;

int n, m;
vector<int> adj[N];
int dist[N], parent[N];

int bfs(int src) {
    memset(dist, -1, sizeof(dist));
    memset(parent, -1, sizeof(parent)); 
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    int res = LLONG_MAX;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
            else if (parent[u] != v) {
                res = min(res, dist[u] + dist[v] + 1);
            }
        }
    }
    return res;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = LLONG_MAX;
    for (int i = 1; i <= n; i++) ans = min(ans, bfs(i));
    
    if (ans == LLONG_MAX) ans = -1;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}