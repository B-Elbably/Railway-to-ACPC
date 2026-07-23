#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    // cout << n / 2 << endl;
    int ans = 0;
    for (int i = 0; i < 40; ++i) {
        if ((n >> i) & 1) continue;
        if (1LL << i > n) break;
        ans += (1LL << i);
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
