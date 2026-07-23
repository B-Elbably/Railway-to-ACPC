#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<vector<char>> a;

void solve() {
    int n, m;
    cin >> n >> m;
    a.resize(n, vector<char>(m));
    for (auto &row : a) {
        for (auto &x : row) {
            cin >> x;
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vis[i][j]) continue;
            queue<pair<pair<int, int>, pair<int, int>>> q;
            q.push({{i, j}, {-1, -1}});
            vis[i][j] = true;
            while (!q.empty()) {
                auto curr = q.front(); q.pop();
                int r = curr.first.first;
                int c = curr.first.second;
                int pr = curr.second.first;
                int pc = curr.second.second;
                for (int k = 0; k < 4; ++k) {
                    int ni = r + dx[k];
                    int nj = c + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && a[ni][nj] == a[r][c]) {
                        if (ni == pr && nj == pc) continue;
                        if (vis[ni][nj]) {
                            cout << "Yes" << endl;
                            return;
                        }
                        vis[ni][nj] = true;
                        q.push({{ni, nj}, {r, c}});
                    }
                }
            }
        }
    }
    cout << "No\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
