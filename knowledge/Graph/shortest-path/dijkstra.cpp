#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pll;

const ll INF = 1e18;
struct Edge {
    int to;
    int weight;
};

vector<ll> dist;
vector<int> parent;
vector<vector<Edge>> adj;

void dijkstra(int n, int start) {
    dist.assign(n + 1, INF);
    parent.assign(n + 1, -1);
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : adj[u]) {
            if (dist[u] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[u] + edge.weight;
                parent[edge.to] = u;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }
}