#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    // k = 100;
    // if (k > 100) {
    //     cout << -1 << endl;
    //     return;
    // }
    int ans = 0;
    int last = -1;
    int cnt = 0;
    for (int i = 0; i < k; ++i) {
        // cout << (y + i) % (x + i) << " "; 
        int now = (y + i) % (x + i);
        ans += now;
        if (cnt == 5) {
            ans += (k - i - 1) * now;
            break;
        }
        if (last == now) {
            cnt++;
        }else {
            cnt = 0;
        }
        last = now;
    }
    cout << ans << endl;
    // cout << endl;
    // cout << endl;
    // cout << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
