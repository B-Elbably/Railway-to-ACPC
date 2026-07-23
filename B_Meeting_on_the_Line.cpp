#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), t(n);
    for (auto &x : a) cin >> x;
    for (auto &x : t) cin >> x;
    double l = 0, r = 1e9;
    for (int i = 0; i < 100; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double c1 = 0, c2 = 0;
        for (int j = 0; j < n; j++) {
            c1 = max(c1, abs(a[j] - m1) + t[j]);
            c2 = max(c2, abs(a[j] - m2) + t[j]);
        }
        if (c1 == c2) {
            l = m1;
            r = m2;
        } else if (c1 < c2) {
            r = m2;
        } else {
            l = m1;
        }
    }
    cout << fixed << setprecision(10) << (l + r) / 2 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
