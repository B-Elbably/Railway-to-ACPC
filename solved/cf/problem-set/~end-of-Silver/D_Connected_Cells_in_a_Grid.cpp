#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int n, m;
int grid[10][10];
bool vis[10][10];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool is_valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m &&
            grid[i][j] == 1 && !vis[i][j];
}

int dfs(int i, int j) {
    vis[i][j] = true;
    int cnt = 1;
    for (int dir = 0; dir < 8; dir++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if (is_valid(nx, ny))
            cnt += dfs(nx, ny);
    }
    return cnt;
}

void solve() {
    memset(vis, 0, sizeof(vis));
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (is_valid(i, j))
                ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
