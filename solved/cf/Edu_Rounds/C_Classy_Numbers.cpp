#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 19;
int dp[2][2][4][N];
string l, r;
int n;
int go(int pos, int t1, int t2, int cnt) {
    if (cnt > 3) return 0;
    if (pos == n) return 1;
    int &ret = dp[t1][t2][cnt][pos];
    if (~ret) return ret;
    ret = 0;
    int mn = t1 ? l[pos] - '0' : 0;
    int mx = t2 ? r[pos] - '0' : 9;
    for (int d = mn; d <= mx; d++) {
        ret += go(pos + 1, t1 && (d == mn), t2 && (d == mx), cnt + (d != 0));
    }
    return ret;
}

void solve() {
    cin >> l >> r;
    n = r.size();
    l = string(n - l.size(), '0') + l;
    memset(dp, -1, sizeof dp);
    cout << go(0, 1, 1, 0) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
