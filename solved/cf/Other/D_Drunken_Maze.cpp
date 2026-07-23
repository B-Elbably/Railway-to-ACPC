#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};

struct state {
    int x, y, d;
};

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve() {
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    state start, end;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                start = {i, j, 4};
            } else if (grid[i][j] == 'T') {
                end = {i, j, 4};
            }
        }
    }
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(5, LLONG_MAX)));
    dist[start.x][start.y][4] = 0;
    queue<state> q;
    q.push(start);
    int ans = LLONG_MAX;
    while (!q.empty()) {
        state cur = q.front(); q.pop();
        int x = cur.x, y = cur.y, d = cur.d;
        if (x == end.x && y == end.y) {
            ans = min(ans, dist[x][y][d]);
        }
        for (int i = 0; i < 4; ++i) {
            if (i == d) continue;
            for (int k = 1; k <= 3; ++k) {
                int nx = x + dx[i] * k, ny = y + dy[i] * k;
                if (!valid(nx, ny)) continue;
                if (grid[nx][ny] == '#') break;
                if (dist[nx][ny][i] > dist[x][y][d] + k) {
                    dist[nx][ny][i] = dist[x][y][d] + k;
                    q.push({nx, ny, i});
                }
            }
        }
    }
    if (ans == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}