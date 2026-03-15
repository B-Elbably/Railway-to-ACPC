#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ans = 0;
    for (int k = 0; k <= 27; ++k) {
        int pref = 0;
        int cnt[2] = {1, 0};
        for (int i = 0; i < n; ++i) {
            pref ^= (a[i] >> k) & 1;
            ans += cnt[pref ^ 1] * 1LL << k;
            cnt[pref]++; 
        }
    }
    cout << ans - accumulate(all(a), 0LL);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}