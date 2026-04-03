#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    sort(all(a)); sort(all(b));
    vector<int> pref(n + 3, 0), suff(n + 3, 0);
    for (int i = 1; i < n; i += 2) {
        pref[i + 1] = a[i] - a[i - 1];
        pref[i + 1] += pref[i - 1];
    }
    for (int i = n - 2; i >= 0; i -= 2) {
        suff[i + 1] = a[i + 1] - a[i];
        suff[i + 1] += suff[i + 3];
    }
    int ans = LLONG_MAX;
    for (int i = 0; i < m; ++i) {
        int idx = upper_bound(all(a), b[i]) - a.begin();
        if (idx % 2 == 0) {
            ans = min(ans, pref[idx] + suff[idx + 2] + abs(a[idx] - b[i]));
        } else {
            ans = min(ans, pref[idx - 1] + suff[idx + 1] + abs(a[idx - 1] - b[i]));
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
