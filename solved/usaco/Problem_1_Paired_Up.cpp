#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    int mn = LLONG_MAX, mx = LLONG_MIN;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x > 1) {
            mn = min(mn, y);
            mx = max(mx, y);
        }else {
            int cnt = 1;
            if (y > mx) {
                cnt--;
                mx = y;
            }
            if (cnt) {
                mn = min(mn, y);
        }
    }
    }
    if (mn == LLONG_MAX) mn = 0;
    if (mx == LLONG_MIN) mx = 0;
    cout << mx + mn << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout); 
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
