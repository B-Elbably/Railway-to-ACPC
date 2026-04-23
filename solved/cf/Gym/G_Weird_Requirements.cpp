#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

#define u128 __uint128_t
u128 gcd_(u128 a, u128 b) {
    while (b) {
        u128 t = a % b;
        a = b;
        b = t;
    }
    return a;
}

u128 lcm_(u128 a, u128 b) {
    return a / gcd_(a, b) * b;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (y % x != 0) {
        cout << -1 << endl;
        return;
    }
    int yy = y / x;
    vector<int> aa;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % x == 0 && (y % a[i]) == 0) {
            aa.push_back(a[i] / x);
        } else {
            ans++;
        }
    }
    if (n == 1) {
        if (x == y) {
            if (a[0] == x) cout << 0 << endl;
            else cout << -1 << endl;
        }else {
            cout << -1 << endl;
            return;
        }
        return;
    }
    if (aa.empty()) {
        cout << ans << endl;
        return;
    }
    int gc = aa[0];
    u128 lc = aa[0];
    n = aa.size();
    for (int i = 1; i < n; i++) {
        gc = __gcd(gc, aa[i]);
        lc = lcm_(lc, aa[i]);
        if (lc > yy) break;
    }
    gc = (gc == 1);
    lc = (lc == yy);
    if (gc && lc) {
        cout << ans << endl;
    } else if (ans) {
        cout << ans << endl;
    } else {
        cout << 2 - (gc || lc) << endl;
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
