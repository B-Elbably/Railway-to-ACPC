#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const long long INF = (1LL << 62);

struct Edge {
    int u, v;
    long long w;
};
vector<Edge> edges;
ll ans = INF;

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
            return;
        }
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = (dist[i] == INF) ? -1 : dist[i];
        ans = min(ans, dist[i]);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    edges.clear();
    edges.reserve(m);
    ll mn = INF;
    for (int i = 0; i < m; i++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
        mn = min(mn, w);
    }
    if (mn >= 0) {
        cout << mn << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        edges.push_back({n + 1, i, 0});
    }
    bellmanFord(n + 1, n + 1);            
    if (ans == INF){
        cout << "-inf" << endl;
        return;
    }
    cout << ans << '\n';
    ans = INF;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}