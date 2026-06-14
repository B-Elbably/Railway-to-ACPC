#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int a, b, d;
    cin >> a >> b >> d;
    double r = (double)d / 2.0;
    double op1 = M_PI * r * r;
    double op2 = (M_PI - 2) * r * r;

    // 2 * r * r (pi - pi)
    cout << r * r * 2 << endl;
    cout << op1 - op2 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}