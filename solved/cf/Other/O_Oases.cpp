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
    int q; cin >> q;
    vector<int> pref(n + 1), suf(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = __gcd(pref[i - 1], a[i - 1]);
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = __gcd(suf[i + 1], a[i]);
    }
    while (q--) {
        int idx; cin >> idx;
        cout << __gcd(pref[idx - 1], suf[idx]) << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
