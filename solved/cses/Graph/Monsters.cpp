#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};

int n, m;
vector<vector<char>> a;
vector<vector<int>> visited;
vector<vector<int>> monster;
vector<vector<pair<int,int>>> parent;
vector<vector<char>> move_dir;

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '#';
}

bool is_scape(int x, int y) {
    return x == 0 || x == n - 1 || y == 0 || y == m - 1;
}

void solve() {
    cin >> n >> m;

    a.assign(n, vector<char>(m));
    visited.assign(n, vector<int>(m, -1));
    monster.assign(n, vector<int>(m, 1e18));
    parent.assign(n, vector<pair<int,int>>(m));
    move_dir.assign(n, vector<char>(m));

    queue<pair<int,int>> mq;
    pair<int,int> start;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'M') {
                mq.push({i, j});
                monster[i][j] = 0;
            }
            if (a[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

    while (!mq.empty()) {
        auto [x, y] = mq.front(); mq.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (is_valid(nx, ny) && monster[nx][ny] > monster[x][y] + 1) {
                monster[nx][ny] = monster[x][y] + 1;
                mq.push({nx, ny});
            }
        }
    }

    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = 0;

    pair<int,int> end = {-1, -1};

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (is_scape(x, y)) {
            end = {x, y};
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (is_valid(nx, ny) && visited[nx][ny] == -1) {
                int nd = visited[x][y] + 1;

                if (nd < monster[nx][ny]) {
                    visited[nx][ny] = nd;
                    parent[nx][ny] = {x, y};
                    move_dir[nx][ny] = dir[i];
                    q.push({nx, ny});
                }
            }
        }
    }

    if (end.first == -1) {
        cout << "NO\n";
        return;
    }

    vector<char> path;
    auto [x, y] = end;

    while (make_pair(x,y) != start) {
        path.push_back(move_dir[x][y]);
        tie(x, y) = parent[x][y];
    }

    reverse(all(path));

    cout << "YES\n";
    cout << path.size() << endl;
    for (char c : path) cout << c;
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}