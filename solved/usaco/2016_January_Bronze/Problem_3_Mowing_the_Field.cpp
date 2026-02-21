#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> grid (2e3+5, vector<int>(2e3 + 5, -1));
    int mn = LLONG_MAX, cnt = 0;
    int x = 1001, y = 1001;
    grid[x][y] = 0;
    for (int i = 0; i < n; ++i){
        char dir;
        int steps;
        cin >> dir >> steps;
        for (int j = 0; j < steps; ++j){
            cnt++;
            if (dir == 'N') x--;
            else if (dir == 'S') x++;
            else if (dir == 'E') y++;
            else if (dir == 'W') y--;
            if (grid[x][y] != -1) {
                mn = min(mn, cnt - grid[x][y]);
            }
            grid[x][y] = cnt;
        }   
    }
    if (mn == LLONG_MAX) {
        cout << -1 << endl;
        return;
    }else {
        cout << mn << endl;
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
