#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int h, v, t;
    cin >> h >> v >> t;
    double ans = sqrt(h * h + v * v);
    if (ans - t < 1e-9) {
        cout << ans << endl; 
    }else {
        cout << t + h - sqrt(t * t - v * v) << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(12);
    freopen("cross.in", "r", stdin);
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
