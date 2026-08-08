#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
using T = long double;

T dist(T x1, T y1, T x2, T y2) {
    T dx = x1 - x2;
    T dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

void solve() {
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    T ans = dist(0, 0, 2 * c + b, a);
    T xx = x / 100.0;
    ans += xx * dist(0, 0, b, a);
    T bb = (1.0 - xx) * b;
    T aa = (1.0  - xx) * a;
    ans += dist(0, 0, 2 * c + bb, aa);
    cout << fixed << setprecision(9) << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}

