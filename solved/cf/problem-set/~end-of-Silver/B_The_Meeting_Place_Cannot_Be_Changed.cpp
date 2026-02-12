#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);  // place, speed
    for (auto &x : a) cin >> x.first;
    for (auto &x : a) cin >> x.second;
    sort(all(a));
    double l = 0, r = 1e15;
    for (int i = 0; i < 200; i++) {
        double mid = (l + r) / 2;
        double L = -1e18;
        double R = 1e18;
        for (int i = 0; i < n; i++) {
            double curL = a[i].first - a[i].second * mid;
            double curR = a[i].first + a[i].second * mid;
            L = max(L, curL);
            R = min(R, curR);
        }
        if (L <= R) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(10) << l << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
