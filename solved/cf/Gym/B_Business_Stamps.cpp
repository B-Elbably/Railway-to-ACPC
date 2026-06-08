#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<unordered_set<int>>> cost(n, vector<unordered_set<int>>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    auto valid = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    queue<pair<pair<int, int>, int>> q;
    q.push({{x1 - 1, y1 - 1}, (1 << grid[x1 - 1][y1 - 1])});
    cost[x1 - 1][y1 - 1].insert(1 << grid[x1 - 1][y1 - 1]);
    int ans = 10;
    while (!q.empty()) {
        auto [x, y] = q.front().first;
        auto st = q.front().second;
        q.pop();
        if (x == x2 - 1 && y == y2 - 1) {
            ans = min(ans, (int)__builtin_popcountll(st));
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny)) {
                int temp = st | (1 << grid[nx][ny]);
                if (__builtin_popcountll(temp) > ans) continue;
                if (cost[nx][ny].find(temp) == cost[nx][ny].end()) {
                    cost[nx][ny].insert(temp);
                    q.push({{nx, ny}, temp});
                }
            }
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}