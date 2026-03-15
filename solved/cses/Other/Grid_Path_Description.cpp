#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
const int N = 7;
int vis[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int ans = 0;
string s;

map<char, int> dir = {
    {'R', 0},
    {'L', 1},
    {'U', 2},
    {'D', 3}
};

bool is_valid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && !vis[x][y];
}

void go(int i, int j, int depth = 0) {
    if (i == 6 && j == 0) {
        if (depth == 48) ans++;
        return;
    }
    if (depth == 48) return;
    
    bool u = (i == 0 || vis[i-1][j]);
    bool d = (i == 6 || vis[i+1][j]);
    bool l = (j == 0 || vis[i][j-1]);
    bool r = (j == 6 || vis[i][j+1]);

    if (u && d && !(l || r)) return;
    if (l && r && !(u || d)) return;

    vis[i][j] = 1;
    
    if (s[depth] != '?') {
        int dir = ::dir[s[depth]];
        if (is_valid(i + dx[dir], j + dy[dir])) {
            go(i + dx[dir], j + dy[dir], depth + 1);
        }
    } else {
        for (int k = 0; k < 4; k++) {
            if (is_valid(i + dx[k], j + dy[k])) {
                go(i + dx[k], j + dy[k], depth + 1);
            }
        }
    }
    vis[i][j] = 0;
}

void solve() {
    cin >> s;
    go(0, 0);
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}