#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 9e4 + 5;
vector<pair<int, int>> adj[N];
const int M = 3e2 + 5;
int cost[M][M];
int dist[M][M];

void bfs(int n, int m, int val) {
    deque<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dist[i][j] = LONG_MAX;
    for (auto [x, y] : adj[val]) {
        dist[x][y] = cost[x][y];
        q.push_back({x, y});
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push_back({nx, ny});
            }
        }
    }

    for (auto [x, y] : adj[val + 1])
        cost[x][y] = dist[x][y];
}

void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cost[i + 1][j + 1] = LONG_MAX;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x; cin >> x;
            adj[x].push_back({i, j});
            if (x == 1) {
                cost[i][j] = i + j - 2;
            }
        }
    }
    int ans = LONG_MAX;
    for (int i = 1; i < p; ++i) {
        if (adj[i].size() * adj[i + 1].size() > n * m) {
            bfs(n, m, i);
            continue;
        }
        for (int j = 0; j < adj[i].size(); ++j) {
            int x1 = adj[i][j].first, y1 = adj[i][j].second;
            for (int k = 0; k < adj[i + 1].size(); ++k) {
                int x2 = adj[i + 1][k].first, y2 = adj[i + 1][k].second;
                cost[x2][y2] = min(cost[x2][y2], cost[x1][y1] + abs(x1 - x2) + abs(y1 - y2));
            }
        }
    }
    for (auto [x, y] : adj[p]) {
        ans = min(ans, cost[x][y]);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
