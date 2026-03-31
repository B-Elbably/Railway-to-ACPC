#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int coins[] = {1, 3, 6, 10, 15};
int memo[100];
int go(int n) {
    if (n < 0) return 1e18;
    if (n == 0) return 0;
    int &ret = memo[n];
    if (~ret) return memo[n];
    ret = 1e18;
    for (int c : coins) {
        ret = min(ret, 1 + go(n - c));
    }
    return ret;
}

void solve() {
    memset(memo, -1, sizeof(memo));
    int n; cin >> n;
    int ans = 0;
    if (n > 30) {
        ans = (n - 30) / 15;
        n -= ans * 15;
    }
    cout << ans + go(n) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
