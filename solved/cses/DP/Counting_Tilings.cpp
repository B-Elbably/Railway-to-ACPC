#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int MOD = 1e9 + 7;
int n, m;
const int N = 10;
const int M = 1e4 + 5;
int dp[M][1 << N];  

int dfs(int i, int mask) {
    if (i == n * m) return mask == 0;
    int &ret = dp[i][mask];
    if (~ret) return ret;
    int r = i % n;
    if (mask & (1 << r)) {
        return ret = dfs(i + 1, mask ^ (1 << r));
    }
    ret = dfs(i + 1, mask | (1 << r));
    if (r + 1 < n && !(mask & (1 << (r + 1)))) {
        ret += dfs(i + 1, mask | (1 << (r + 1)));
        ret %= MOD;
    }
    return ret;
}

void solve() {
    cin >> n >> m;
    if (n * m % 2) {
        cout << 0 << endl;
        return;
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
