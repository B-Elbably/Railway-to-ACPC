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
    vector<int> pref(n + 1), suff(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = max(pref[i], a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = max(suff[i + 1], a[i]);
    }
    // for (int x: pref) cout << x << " "; cout << endl;
    // for (int x: suff) cout << x << " "; cout << endl;
    int ans = LLONG_MAX;
    for (int i = 1; i < n - 1; i++) {
        ans = min(ans, pref[i] + a[i] + suff[i + 1]);
    }
    if (a[0] != n && a[n - 1] != n) {
        ans = min(ans, a[0] + n + a[n - 1]);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
