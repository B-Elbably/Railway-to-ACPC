#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const double INF = 1e15;
const double EPS = 1e-9;
const int N = 505;

double dist[N][N];
int n, m;

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] >= INF || dist[k][j] >= INF) continue;
                if (dist[i][k] + dist[k][j] >= dist[i][j] - EPS) continue;
                dist[i][j] = max(-INF, dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int t = 1; t <= n; t++) {
                if (dist[i][t] >= INF || dist[t][j] >= INF) continue;
                if (dist[t][t] >= -EPS) continue;
                
                dist[i][j] = -INF;
                break;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }

    while (m--) {
        int u, v;
        double w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }

    floyd();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] > INF * 0.5) cout << "INF ";
            else if (dist[i][j] < -INF * 0.5) cout << "-INF ";
            else cout << fixed << setprecision(4) << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--) solve();
    return 0;
}