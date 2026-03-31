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

    vector<string> grid(n);
    vector<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') continue;
            int ok = 0;
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (0 <= ni && ni < n && 0 <= nj && nj < m) {
                    if (grid[ni][nj] == '*') {
                        ok++;
                    }
                }
            }
            if (ok == 4) {
                q.emplace_back(i, j);
            }
        }
    }
    if (q.size() != 1) {
        cout << "NO" << endl;
        return;
    }
    int x = q[0].first;
    int y = q[0].second;
    // grid[x][y] = '.';
    // if ((x == 0) || (y == 0) || (x == n - 1) || (y == m - 1)) {
    //     cout << "NO";
    //     return;
    // }
    int ok = 0;
    for (int k = 0; k < 4; k++) {
        int ni = x + dx[k];
        int nj = y + dy[k];
        if ((0 <= ni) &&( ni < n) && (0 <= nj) && (nj < m)) {
            if (grid[ni][nj] == '*') {
                ok++;
            }
        }
    }
    if (ok != 4){
        cout << "NO";
        return;
    }
    grid[x][y] = '.';

    for (int i = x + 1; i < n && grid[i][y] == '*'; i++)
        grid[i][y] = '.';

    for (int i = x - 1; i >= 0 && grid[i][y] == '*'; i--)
        grid[i][y] = '.';

    for (int j = y + 1; j < m && grid[x][j] == '*'; j++)
        grid[x][j] = '.';

    for (int j = y - 1; j >= 0 && grid[x][j] == '*'; j--)
        grid[x][j] = '.';
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
