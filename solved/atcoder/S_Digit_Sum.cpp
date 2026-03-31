#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const int K = 105;
string s;
int d, n;
int dp[2][K][N];

int go(int i, int sum, int flag) {
    if (i == n) return sum == 0;
    int &ret = dp[flag][sum][i];
    if (~ret) return ret;
    int mx = (flag ? s[i] - '0' : 9);
    ret = 0;
    for (int j = 0; j <= mx; j++) {
        ret += go(i + 1, (sum + j) % d, flag && (j == mx));
        ret %= MOD;
    }
    return ret;
}

void solve() {
    cin >> s >> d;
    n = s.size();
    memset(dp, -1, sizeof(dp));
    int ans = go(0, 0, 1) - 1;
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
