#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int n, m;
char g[55][55];
bool vis[55][55];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(int x, int y) {
    return x >= 0 && x < n &&
            y >= 0 && y < m &&
            g[x][y] != '#';
}

void dfs(int x, int y) {
    if (!valid(x, y) || vis[x][y])
        return;
    vis[x][y] = true;
    for (int k = 0; k < 4; k++)
        dfs(x + dx[k], y + dy[k]);
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] != 'B') continue;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (!valid(x, y)) continue;
                if (g[x][y] == '.') g[x][y] = '#';
                if (g[x][y] == 'G') {
                    cout << "No\n";
                    return;
                }
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    if (g[n - 1][m - 1] != '#') dfs(n - 1, m - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool G = g[i][j] == 'G' && !vis[i][j];
            bool B = g[i][j] == 'B' &&  vis[i][j];
            if (G || B) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}