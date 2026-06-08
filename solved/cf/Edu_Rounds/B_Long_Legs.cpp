#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

set<int> factorize(int x) {
    set<int> factors = {1, x};
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            factors.insert(i);
            factors.insert(x / i);
        }
    }
    if (x > 1) factors.insert(x);
    return factors;
}

void solve() {
    int a, b;
    cin >> a >> b;
    set<int> fa = factorize(a);
    set<int> fb = factorize(b);
    int ans = a + b;
    // for (int x: fa) {
    //     for (int y: fb) {
    //         int res = max(x, y) - 1;
    //         res += a / x;
    //         res += b / y;
    //         ans = min(ans, res);
    //     }
    // }
    for (int i = 1; i * i <= 10 * max(a, b); ++i) {
        ans = min(ans, i - 1 + (a + i - 1) / i + (b + i - 1) / i);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
