#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    while (k > 0 && x > 1) {
        int need = (y - x % y) % y;
        if (need == 0) need = y;
        if (need > k) {
            x += k;
            k = 0;
            break;
        }
        x += need;
        k -= need;
        while (x % y == 0) x /= y;
    }
    if (x == 1) 
        x = 1 + (k % (y - 1));
    
    cout << x << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}
