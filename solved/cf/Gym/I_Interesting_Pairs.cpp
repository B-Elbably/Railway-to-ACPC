#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int l, r, k; 
    cin >> l >> r >> k;
    int ans = 0;
    for (int i = 1; i * i <= k; ++i) {
        if (k % i == 0) {
            if (__gcd(i, k / i) != 1) continue;
            int mn = (l + i - 1) / i;
            int mx = r / (k / i);
            ans += max(0LL, mx - mn + 1);
        }
    }
    cout << ans << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
