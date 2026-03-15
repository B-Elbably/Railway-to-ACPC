#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];
    int ans = LLONG_MIN;
    multiset<int> s;
    for (int i = l; i <= n; i++) {
        if (i > r)
            s.erase(s.find(pref[i - r - 1]));
        s.insert(pref[i - l]);
        ans = max(ans, pref[i] - *s.begin());
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
