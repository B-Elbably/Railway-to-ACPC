#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 5e2 + 5;
int dp[N][N];
int n;
string s;

int dfs(int i, int j) {
    if (i > j) return 0;
    int &ret = dp[i][j];
    if (~ret) return ret;
    ret = 1 + dfs(i + 1, j);
    for (int k = i; k <= j; k++) {
        if (s[k] != s[i]) continue;
        int op1 = dfs(i + 1, k - 1);
        int op2 = dfs(k, j);
        ret = min(ret, op1 + op2);
    }
    return ret;
}

void solve() {
    cin >> n >> s;
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, n - 1) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
