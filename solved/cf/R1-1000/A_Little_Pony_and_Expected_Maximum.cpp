#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int m, n;
    cin >> m >> n;
    double ans = 0.0;
    for (int i = 1; i <= m; ++i) {
        ans += i * (pow((double)i / m, n) - pow((double)(i - 1) / m, n));
    }
    cout << fixed << setprecision(12) << ans << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
