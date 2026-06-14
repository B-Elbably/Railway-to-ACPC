#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'


void solve() {
    int l, r, d;
    cin >> l >> r >> d;
    if (d < l) {
        cout << d << endl;
    } else {
        int ans = (r / d + 1) * d;
        cout << ans << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
