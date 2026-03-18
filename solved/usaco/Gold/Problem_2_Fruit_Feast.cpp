#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int t, a, b;
const int N = 5e6 + 5;
bool dp[N][2];
void go(int i, bool used) {
    if (i > t ) return;
    bool &ret = dp[i][used];
    if (ret) return;
    ret = true;
    go(i + a, used);
    go(i + b, used);
    if (!used) {
        go(i / 2, true);
    }
}
void solve() {
    cin >> t >> a >> b;
    // go(a, false);
    // go(b, false);
    go(0, false);
    int ans = 0;
    for (int i = 0; i <= t; i++) {
        if (dp[i][false] || dp[i][true]) ans = i;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
