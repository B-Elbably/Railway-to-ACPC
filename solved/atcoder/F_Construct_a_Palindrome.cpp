#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int dist[1005][1005];
vector<int> adj[1005][26];
bool edge[1005][1005];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; char c;
        cin >> u >> v >> c;
        adj[u][c - 'a'].push_back(v);
        adj[v][c - 'a'].push_back(u);
        edge[u][v] = edge[v][u] = true;
    }
    memset(dist, INF, sizeof(dist));
    queue<pair<int, int>> q;
    dist[1][n] = 0;
    q.push({1, n});
    int ans = INF;
    while (!q.empty()) {
        auto [u, v] = q.front();
        q.pop();
        if (dist[u][v] >= ans) continue;
        if (u == v) {
            ans = min(ans, dist[u][v] * 2);
            continue;
        }
        if (edge[u][v]) {
            ans = min(ans, dist[u][v] * 2 + 1);
        }
        for (int c = 0; c < 26; c++) {
            if (adj[u][c].empty() || adj[v][c].empty()) continue;
            for (int nu : adj[u][c]) {
                for (int nv : adj[v][c]) {
                    int cost = dist[u][v] + 1;
                    if (dist[nu][nv] > cost) {
                        dist[nu][nv] = cost;
                        q.push({nu, nv});
                    }
                }
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << (dist[i][j] == INF ? -1 : dist[i][j]) << ' ';
    //     }
    //     cout << endl;
    // }
    cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}