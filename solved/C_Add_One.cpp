#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 2e5 + 5, MOD = 1e9 + 7;
int dp[10][N];

int go(int x, int m){
    if (m == 0) return 1;
    int &ret = dp[x][m];
    if (~ret) return ret;
    ret = 0;
    if (x + 1 == 10) {
        ret += go(1, m - 1);
        ret += go(0, m - 1);
        ret %= MOD;
    }else {
        ret += go(x + 1, m - 1);
        ret %= MOD;
    }
    return ret;
}

void solve() {
    int n, m, ans = 0;
    cin >> n >> m;
    while (n)
    {
        ans += go(n % 10, m);
        n /= 10; ans %= MOD;
    }
    cout << ans << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof dp);
    int t = 1;
    cin >> t; 
    while (t--) solve();
}
