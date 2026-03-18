#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
int n, x;
int s[105];
int memo[105][105][5005];

int dp(int i, int j, int sum) {
    if (i == n) {
        return (j == 0 && sum <= x) ? 1 : 0;
    }
    if (~memo[i][j][sum]) return memo[i][j][sum];
    int res = 0;
    res = (res + (1 + j) * dp(i + 1, j, sum)) % MOD;
    if (j > 0) {
        res = (res + j * dp(i + 1, j - 1, sum + s[i])) % MOD;
    }
    if (j + 1 <= n) {
        res = (res + dp(i + 1, j + 1, sum - s[i])) % MOD;
    }
    return memo[i][j][sum] = res;
}

void solve() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s, s + n);
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0, 0) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}