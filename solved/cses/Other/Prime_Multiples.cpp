#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) cin >> a[i];
    int ans = 0;
    for (int mask = 1; mask < (1 << k); ++mask) {
        int lcm = 1;
        int ok = 0;
        for (int i = 0; i < k; ++i) {
            if ((mask >> i) & 1) {
                ok ^= 1;
                if (lcm > n / a[i]) {lcm = n + 1; break;}
                lcm *= a[i];
            }
        }
        ans += (ok ? 1 : -1) * (n / lcm);
    }
    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
