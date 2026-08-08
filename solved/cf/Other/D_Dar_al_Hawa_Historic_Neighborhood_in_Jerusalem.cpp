#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
using T = long double;

void solve() {
    int R, n;
    cin >> R >> n;
    T ans = R;
    for (int i = 0; i < n; ++i) {
        ans = ans * sqrt(2.0) - ans;
        ans /= (1.0 + sqrt(2.0));
        if (ans - 0 < 1e-9) {
            cout << "0.000000000\n";
            return;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(9);
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
