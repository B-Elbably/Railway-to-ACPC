#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pll;

const ll INF = 1e18;
const int N = 5005; 

struct ListEdge {
    int u, v;
    ll w;
};

struct AdjEdge {
    int to;
    ll weight;
};

vector<ListEdge> edges;
vector<AdjEdge> adj[N];
ll h[N];
ll dist[N];

bool bellmanFord(int n) {
    fill(h, h + n + 1, 0);

    for (int i = 1; i <= n - 1; i++) {
        bool ok = false;
        for (const auto &e : edges) {
            if (h[e.u] + e.w < h[e.v]) {
                h[e.v] = h[e.u] + e.w;
                ok = true;
            }
        }
        if (!ok) break;
    }

    for (const auto &e : edges) {
        if (h[e.u] + e.w < h[e.v]) {
            return false; 
        }
    }
    return true;
}

void dijkstra(int start, int n) {
    for (int i = 0; i <= n; i++) {
        dist[i] = INF;
    }
    
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto &edge : adj[u]) {
            if (dist[u] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[u] + edge.weight;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }
}

vector<vector<ll>> johnson(int n) {
    if (!bellmanFord(n)) return {}; 

    for (int u = 1; u <= n; u++) {
        for (auto &edge : adj[u]) {
            edge.weight += h[u] - h[edge.to];
        }
    }

    vector<vector<ll>> all_dist(n + 1, vector<ll>(n + 1, INF));
    
    for (int i = 1; i <= n; i++) {
        dijkstra(i, n);
        for (int j = 1; j <= n; j++) {
            if (dist[j] != INF) {
                all_dist[i][j] = dist[j] - h[i] + h[j];
            }
        }
    }
    
    return all_dist;
}

void solve() {
    int n, m;
    cin >> n >> m;

    edges.clear();
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        adj[u].push_back({v, w}); 
    }

    vector<vector<ll>> result = johnson(n);

    if (result.empty()) {
        cout << "-1\n"; 
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    while (t--) solve();
    
    return 0;
}