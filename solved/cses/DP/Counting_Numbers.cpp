#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

string a, b;
int n;
int dp[2][2][2][11][20];
int go(int i, int last, int lo, int hi, int lead) {
    if (i == n) return 1;
    int &ret = dp[lo][hi][lead][last][i];
    if (~ret) return ret;
    ret = 0;
    int mn = lo ? a[i] - '0' : 0;
    int mx = hi ? b[i] - '0' : 9;
    for (int j = mn; j <= mx; j++) {
        int z = lead && (j == 0);
        if (!z && j == last) continue;
        int prev = z ? -1 : j;
        int l = lo && (j == mn);
        int r = hi && (j == mx);
        ret += go(i + 1, prev, l, r, z);
    }
    return ret;
}

void solve() {
    cin >> a >> b;
    n = b.size();
    a = string(n - a.size(), '0') + a;
    memset(dp, -1, sizeof(dp));
    cout << go(0, -1, true, true, true) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
