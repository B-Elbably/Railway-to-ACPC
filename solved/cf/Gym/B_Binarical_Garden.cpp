#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int l, r;
    cin >> l >> r;
    while ((l | (l + 1)) <= r) l |= l + 1;
    int ans = 0;
    while (l) {
        ans += l & 1;
        l >>= 1;
    }
    cout << ans;    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
