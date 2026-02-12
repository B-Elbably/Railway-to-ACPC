#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(x);
    for (int i = 0; i < x; i++) cin >> a[i];
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for (int now : a) {
        for (int i = now; i <= n; i++) {
            dp[i] += dp[i - now];
        }
    }
    cout << dp[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) solve();
}
