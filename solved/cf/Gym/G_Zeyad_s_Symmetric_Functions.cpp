#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int l, r;
    cin >> l >> r;
    int ans = r - l + 1;
    if (l <= 0 && r >= 0) ans--;
    cout << 2 * ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}