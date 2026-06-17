#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        int f2 = n;
        int f1 = i;
        bool ok = true;
        for (int j = 0; j < k - 2; ++j) {
            int f0 = f2 - f1;
            if (f0 > f1 || f0 < 0) {
                ok = false;
                break;
            }
            f2 = f1;
            f1 = f0;
        }
        if (ok) {
            ans++;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}