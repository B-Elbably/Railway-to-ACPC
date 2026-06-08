#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
vector<vector<int>> grid;
int sum = 0;
int n, m, k;
int r0, c0, r1, c1;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int calc(int x, int y) {
    int res = 0;
    for (int d = 0; d < 8; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (is_valid(nx, ny)) {
            res += grid[nx][ny];
        }
    }
    return res;
}

vector<vector<int>> _grid;
void update(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = calc(i, j);
            if (grid[i][j] == 0 && x == 4) {
                _grid[i][j] = 1;
            }else if (x <= 5 && x >= 3) {
                _grid[i][j] = grid[i][j];
            }else {
                _grid[i][j] = 0;
            }
        }
    }
    swap(grid, _grid);
}

void solve() {
    cin >> n >> m >> k;
    grid.assign(n, vector<int>(m));
    _grid.assign(n, vector<int>(m));
    cin >> r0 >> c0 >> r1 >> c1;
    r0--; c0--; r1--; c1--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < k; ++i) {
        update();
    } 
    for (int i = r0; i <= r1; i++) {
        for (int j = c0; j <= c1; j++) {
        sum += grid[i][j];
        }
    }
    cout << sum << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
