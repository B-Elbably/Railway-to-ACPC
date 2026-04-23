#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int INF = 1e18;

vector<vector<int>> dijkstra(int start, int n, const vector<int>& freq, const vector<vector<pair<int, int>>>& adj) {
    vector<vector<int>> dist(n + 1, vector<int>(2, INF));
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;

    dist[start][freq[start]] = 0;
    pq.push({0, start, freq[start]});

    while (!pq.empty()) {
        auto [d, u, f] = pq.top(); pq.pop();
        if (d > dist[u][f]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            int nf = (f || freq[v]);
            int nw = f ? w / 2 : w;
            if (dist[v][nf] > d + nw) {
                dist[v][nf] = d + nw;
                pq.push({dist[v][nf], v, nf});
            }
        }
    }
    return dist;
}

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < h; i++) {
        int x; cin >> x; freq[x] = 1;
    }
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<vector<int>> dist1 = dijkstra(1, n, freq, adj);
    vector<vector<int>> dist2 = dijkstra(n, n, freq, adj);

    int ans = INF;
    for (int i = 1; i <= n; i++) {
        int d1 = min(dist1[i][0], dist1[i][1]);
        int d2 = min(dist2[i][0], dist2[i][1]);
        if (d1 == INF || d2 == INF) continue;
        ans = min(ans, max(d1, d2));
    }

    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}