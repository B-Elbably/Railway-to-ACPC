#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
int m, d, n;
string a, b;
int memo[2005][2005][2][2];

int go(int i, int md, int lo, int hi) {
    if (i == n) return md == 0;
    int &ret = memo[i][md][lo][hi];
    if (~ret) return ret;
    ret = 0;
    int mn = lo ? a[i] - '0' : 0;
    int mx = hi ? b[i] - '0' : 9;

    for (int j = mn; j <= mx; j++) {
        if (i % 2 == 1) {
            if (j != d) continue;
        } else {
            if (j == d) continue;
        }
        int md_ = (md * 10 + j) % m;
        int lo_ = lo && (j == mn);
        int hi_ = hi && (j == mx);
        ret = (ret + go(i + 1, md_, lo_, hi_)) % MOD;
    }
    return ret;
}

void solve() {
    cin >> m >> d >> a >> b;
    n = b.length();
    memset(memo, -1, sizeof(memo));
    cout << go(0, 0, 1, 1) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}