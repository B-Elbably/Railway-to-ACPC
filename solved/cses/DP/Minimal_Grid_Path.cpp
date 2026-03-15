#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int dx[] = {0, 1};
int dy[] = {1, 0};

void solve() {
    int n;
    cin >> n;

    vector<string> a(n);
    for (auto &x : a) cin >> x;

    vector<vector<int>> vis(n, vector<int>(n, 0));

    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0][0] = 1;

    while (!q.empty()) {
        int sz = q.size();
        vector<pair<int,int>> cur;
        char mn = 'Z' + 1;

        for (int i = 0; i < sz; i++) {
            auto [x,y] = q.front();
            q.pop();
            cur.push_back({x,y});

            for (int j = 0; j < 2; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx >= n || ny >= n || vis[nx][ny]) continue;
                mn = min(mn, a[nx][ny]);
            }
        }

        for (auto [x,y] : cur) {
            for (int j = 0; j < 2; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx >= n || ny >= n || vis[nx][ny]) continue;
                if (a[nx][ny] == mn) {
                    vis[nx][ny] = vis[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
    vector<char> ans;
    int x = n-1, y = n-1;
    while (x != 0 || y != 0) {
        ans.push_back(a[x][y]);
        if (x > 0 && vis[x][y] == vis[x-1][y] + 1)
            x--;
        else
            y--;
    }
    ans.push_back(a[0][0]);
    reverse(all(ans));
    for (char c : ans) cout << c;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}