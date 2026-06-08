#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int x, l, r;
    cin >> x >> l >> r;
    for (int i = l; i <= r - 2; i++) {
        for (int j = i + 1; j <= r - 1; j++) {
            int k = x;
            if (x % i) continue;
            k /= i;
            if (x % j) continue;
            k /= j;
            if (k <= j) continue;
            if (k > r || k < l) continue;
            cout << i << ' ' << j << ' ' << k << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
