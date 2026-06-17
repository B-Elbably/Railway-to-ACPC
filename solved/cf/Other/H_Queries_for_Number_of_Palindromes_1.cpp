#include <bits/stdc++.h>
using namespace std;

#define int long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n;
string s;
const int N = 5e3 +5;
int dp[N][N];
int ok[N][N];

int dfs1(int i, int j) {
    if (i >= j) return 1;
    int &ret = ok[i][j];
    if (~ret) return ret;
    return ret = (s[i] == s[j]) && dfs1(i + 1, j - 1);
}

int dfs2(int i, int j) {
    if (i > j) return 0;
    int &ret = dp[i][j];    
    if (~ret) return ret;
    ret = dfs2(i + 1, j) 
    + dfs2(i, j - 1) - dfs2(i + 1, j - 1);
    dfs1(i, j);
    if (ok[i][j]) ret++;
    return ret;
}

void solve() {
    cin >> s;
    n = s.size();
    int q;
    cin >> q;
    memset(dp, -1, sizeof(dp));
    memset(ok, -1, sizeof(ok));
    dfs2(0, n - 1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << dp[--l][--r] << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
