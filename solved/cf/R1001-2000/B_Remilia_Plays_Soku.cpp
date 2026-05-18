#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;
    if (x1 > x2) swap(x1, x2);
    int ans = min(x2 - x1, n - x2 + x1);
    ans += k;
    if (n < 4) ans = 1;
    cout << ans << endl;
}

// 0 0 0

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
