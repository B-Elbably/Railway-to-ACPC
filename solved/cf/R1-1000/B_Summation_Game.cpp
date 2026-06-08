#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define endl '\n'

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (auto &v : a) cin >> v;
    sort(allr(a));
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    int ans = LLONG_MIN;
    for (int i = 0; i <= k; i++) {
        int add = pref[n] - pref[i];
        int sub = 2 * (pref[min(n, i + x)] - pref[i]);
        ans = max(ans, add - sub);
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
