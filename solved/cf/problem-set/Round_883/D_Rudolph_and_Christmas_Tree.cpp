#include <bits/stdc++.h>
using namespace std;

#define int double
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, d, h;
    cin >> n >> d >> h;
    vector<int> y(n);
    for (auto &x : y) cin >> x;
    int ans = d * h / 2;
    for (int i = 0; i < n - 1; i++) {
        int now = d * h / 2;
        int H = max(0.0, y[i] + h - y[i + 1]);
        int D = d * H / h;
        now -= D * H / 2;
        ans += now;
    }
    cout << fixed << setprecision(7) << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
