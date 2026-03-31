#include <iostream>
#include <vector>


using namespace std;

const long long INF = (1LL << 62);

struct Edge {
    int u, v;
    long long w;
};
vector<Edge> edges;

// O(n * m) 
void bellmanFord(int n, int u) {
    vector<long long> dist(n + 1, INF);
    dist[u] = 0;

    for (int i = 1; i <= n - 1; i++) {
        bool ok = false;
        for (const auto &e : edges) {
            if (dist[e.u] < INF) {
                if (dist[e.u] + e.w < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                    ok = true;
                }
            }
        }
        if (!ok) break;
    }

    for (const auto &e : edges) {
        if (dist[e.u] < INF && dist[e.u] + e.w < dist[e.v]) {
            cout << "-1" << endl;
            return;
        }
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = (dist[i] == INF) ? -1 : dist[i];
        cout << dist[i] << " ";
    }
    cout << '\n';
}

void solve() {
    int n, m, u;
    cin >> n >> m >> u;

    edges.clear();
    edges.reserve(m);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
    }

    bellmanFord(n, u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}