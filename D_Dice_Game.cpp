#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << -1 << endl;
        return;
    }
    if (n == 7) {
        cout << 3 << endl;
        return;
    }
    int ans = n / 11 * 2;
    n %= 11;
    if (!n) {
        cout << ans << endl;
    }else {
        ans++;
        if (n >= 6) ans++;
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
