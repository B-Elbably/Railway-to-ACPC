#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int l, r;
    cin >> l >> r;
    int ans = 18 >= l && 18 <= r;
    cout << ans << "\n";
    // int cnt = 0;
    // for (int i = 1; i < 10000; ++i) {
    //     for (int j = i + 1; j < 10000; ++j) {
    //         int area = i * j;
    //         int p = (i + j) * 2;
    //         if (area != p) continue;
    //         // if (area >= l && area <= r && p >= l && p <= r) {
    //             // cnt++;
    //         cout << i << " " << j << endl;
    //         // }
    //     }
    // }
    // cout << cnt << "\n"; 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
