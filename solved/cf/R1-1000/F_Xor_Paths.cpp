#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n, m, k, ans, mm;
vector<vector<int>> a;
map<int, int> mp[20][20];

void dfs(int i, int j, int val) {
    if (i >= n || j >= m) return;
    val ^= a[i][j];
    mp[i][j][val]++; 
    if (i + j == mm) { 
        return; 
    }
    dfs(i + 1, j, val);
    dfs(i, j + 1, val);
}

void dfs2(int r, int c, int val) {
    if (r < 0 || c < 0) return;
    if (r + c == mm) { 
        ans += mp[r][c][k ^ val]; 
        return; 
    }
    val ^= a[r][c];
    dfs2(r - 1, c, val);
    dfs2(r, c - 1, val);
}

void solve() {
    cin >> n >> m >> k;
    a.assign(n, vector<int>(m));
    for (auto &x : a) {
        for (auto &y : x) cin >> y;
    }
    mm = (n + m - 2) / 2;
    ans = 0;
    dfs(0, 0, 0);
    dfs2(n - 1, m - 1, 0);
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}