#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int calc(int l, int r) {
    return r * (r + 1) / 2 - (l - 1) * l / 2;
}

void solve() {
    int a, b;
    cin >> b >> a;
    b += a - 1;
    int l = a, r = b;
    int ans = INT_MAX;
    while (l + 3 < r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int p1 = calc(a, m1); int p2 = calc(m1 + 1, b);
        int p3 = calc(a, m2); int p4 = calc(m2 + 1, b);
        ans = min(ans, abs(p1 - p2));
        ans = min(ans, abs(p3 - p4));
        if (abs(p1 - p2) < abs(p3 - p4)) {
            r = m2;
        } else {
            l = m1;
        }
    }
    for (int i = l; i <= r; i++) {
        int p1 = calc(a, i);
        int p2 = calc(i + 1, b);
        ans = min(ans, abs(p1 - p2));
    }
    cout << ans << endl;
    // int ans = INT_MAX;
    // for (int i = (a + b) / 2 ; i < min((a + b) / 2 + 100, b); i++) {
    //     int p1 = calc(a, i);
    //     int p2 = calc(i + 1, b);
    //     // cout << abs(p1 - p2) << " ";
    //     ans = min(ans, abs(p1 - p2));
    // }
    // for (int i = max((a + b) / 2 - 100, a); i < (a + b) / 2 + 100; i++) {
    //     int p1 = calc(a, i);
    //     int p2 = calc(i + 1, b);
    //     // cout << abs(p1 - p2) << " ";
    //     ans = min(ans, abs(p1 - p2));
    // }
    // cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
