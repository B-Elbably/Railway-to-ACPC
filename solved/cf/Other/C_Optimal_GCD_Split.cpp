#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int lcm__(int a, int b) {
    return a / __gcd(a, b) * b;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> pref(n + 1, 0), suf(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = __gcd(pref[i], a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = __gcd(suf[i + 1], a[i]);
    }
    a[n - 1] = 1;
    for (int i = n - 2; i >= 1; i--) {
        a[i] = (suf[i + 1] % pref[i] == 0) ||
                (pref[i + 1] == pref[i] && a[i + 1]);
    }
    a[0] = 1;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (i > 1) {
            a[0] = (pref[i - 1] % suf[i] == 0) ||
                    (suf[i - 1] == suf[i] && a[0]);
        }
        if (a[0] || a[i]) ans++;
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
