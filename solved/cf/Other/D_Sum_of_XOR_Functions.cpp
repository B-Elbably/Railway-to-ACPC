#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ans = 0;
    for (int k = 0; k <= 30; ++k) {
        int pref = 0;
        int cnt[2] = {1, 0};
        int idx[2] = {-1, 0}; 
        for (int i = 0; i < n; ++i) {
            pref ^= (a[i] >> k) & 1;
            int len = (i * cnt[pref ^ 1] - idx[pref ^ 1]) % MOD;
            ans += (len * ((1LL << k) % MOD)) % MOD;
            ans %= MOD;
            cnt[pref]++; 
            idx[pref] += i; 
        }
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