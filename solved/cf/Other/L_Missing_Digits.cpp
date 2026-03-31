#include <bits/stdc++.h>
using namespace std;

#define int long long

string s;
int memo[20][2][2][2];

int go(int i, bool up, bool ok4, bool ok7) {
    if (i == s.size()) return ok4 && ok7;
    int &ret = memo[i][up][ok4][ok7];
    if (~ret) return ret;
    ret = 0;
    int r = up ? 9 : s[i] - '0';
    for (int j = 0; j <= r; j++) {
        int up_ = up || (j < r);
        int ok4_ = ok4 || (j == 4);
        int ok7_ = ok7 || (j == 7);
        ret += go(i + 1, up_, ok4_, ok7_);
    }
    return ret;
}

int calc(int n) {
    s = to_string(n);
    memset(memo, -1, sizeof(memo));
    return go(0, 0, 0, 0);
}

void solve() {
    int k;
    cin >> k;
    int lo = 1, hi = 2e18, ans = hi;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (mid - calc(mid) >= k) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}