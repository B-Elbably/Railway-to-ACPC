#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pll;

const int INF = 1e18;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
struct Edge {
    int to;
    int weight;
};

vector<Edge> adj[N];
int dist[N], num[N], mn[N], mx[N];
int parent[N];

void dijkstra(int start, int n) {
    for (int i = 0; i <= n; i++) {
        dist[i] = INF;
        parent[i] = -1;
        num[i] = 0;
        mn[i] = INF;
        mx[i] = -INF;
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dist[start] = 0;
    mn[start] = 0;
    mx[start] = 0;
    num[start] = 1;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto &edge : adj[u]) {
            int v = edge.to;
            int w = edge.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                num[v] = num[u];
                mn[v] = mn[u] + 1;
                mx[v] = mx[u] + 1;
                parent[v] = u;
                pq.push({dist[v], v});
            }else if (dist[u] + w == dist[v]) {
                num[v] = (num[v] + num[u]) % MOD;
                mn[v] = min(mn[v], mn[u] + 1);
                mx[v] = max(mx[v], mx[u] + 1);
            }
        }
    }
}

vector<int> get_path(int u) {
    vector<int> path;
    if (dist[u] == INF) return path; 
    for (int v = u; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }
    dijkstra(1, n);
    cout << dist[n] << " " << num[n] << " " << mn[n] << " " << mx[n] << "\n";
    return 0;
}