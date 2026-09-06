#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int b, d, c, k, t;
    cin >> b >> d >> c >> k >> t;
    for (int i = 1; i <= t && b; ++i) {
        b -= d;
        b = max(b, 0LL);
        if (!b) break;
        if (i % k == 0) {
            b += c;
            b = min(b, 100LL);
        }
    }
    cout << b;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
