#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int n, m;
vector<vector<int>> a;

bool is_valid(int i , int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

void solve() {
    cin >> n >> m;
    a.assign(n, vector<int>(m));  
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            sum += a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cur = sum;
            for (int k = 0; k < 8; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (!is_valid(x , y)) continue;
                if (a[x][y] == 0) {
                    cur++;
                }
            }

            if (cur == n * m) {
                cout << "WIN";
                return;
            }

            for (int k = 0; k < 8; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (!is_valid(x , y)) continue;
                if (a[x][y] == 0) {
                    cur--;
                }
            }
    }}
    cout << "LOSE";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
