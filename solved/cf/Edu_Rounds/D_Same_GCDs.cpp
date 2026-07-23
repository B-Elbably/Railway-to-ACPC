#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int a, m;
    cin >> a >> m;
    int g = gcd(a, m);
    m /= g;
    int ans = m;
    for (int i = 2; i * i <= m; ++i) {
        if (m % i == 0) {
            while (m % i == 0) m /= i;
            ans -= ans / i;
        }
    }
    if (m > 1) ans -= ans / m;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;e GCDs 
}

