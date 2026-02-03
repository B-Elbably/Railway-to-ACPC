#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) {cin >> x; x %= m;}
    sort(all(a));
    for (int i = 0; i < n; ++i) {
        a.push_back(a[i] + m);
    }
    vector<int> pref(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; ++i) pref[i] = pref[i - 1] + a[i - 1];

    int ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        int median = a[i + n / 2];
        int idx = upper_bound(a.begin() + i, a.begin() + i + n, median) - a.begin();
        // (median * (idx - i)) - sum[l:idx]
        //  + sum[idx:n + i] - (median * (n + i - idx))
        int part1 = median * (idx - i) - (pref[idx] - pref[i]);
        int part2 = (pref[i + n] - pref[idx]) - median * (n + i - idx);
        ans = min(ans, part1 + part2);
        // ans = min(ans, a[i + n] - a[idx]);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
