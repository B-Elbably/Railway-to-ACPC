#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 3e3 + 5;
int n;
int a[N];
int memo[N][N];
int go(int i, int j) {
    if (i > j) return 0;
    int &ret = memo[i][j];
    if (~ret) return ret;
    int sign = (i + n - j) & 1;
    if (sign) {
        ret = max(sign * a[i] + go(i + 1, j), sign * a[j] + go(i, j - 1));
    }else {
        ret = min(sign * a[i] + go(i + 1, j), sign * a[j] + go(i, j - 1));
    }
    return ret;
}

void solve() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {cin >> a[i]; sum += a[i];}
    memset(memo, -1, sizeof memo);
    int ans = go(0, n - 1);
    sum -= ans;
    cout << ans - sum << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
