#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

// int diff(int a, int b) {
//     int res = 0;
//     for (int i = 0; i < 11; ++i) {
//         a >>= i; b >>= i;
//         res += (a & 1) != (b & 1);
//     }
//     return res;
// }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ans = 0;
    // for (int i = 1; i < n; ++i) {
    //     a[i - 1] ^= a[i];
    // }
    // n -= 1;
    int cnt;
    for (int j = 0; j < 11; ++j) {
        int res = LLONG_MAX;
        // 
        cnt = 0;
        for(int i = 0; i < n; ++i) {
            cnt += (a[i] >> j) & 1;
        }
        cnt = min(cnt, n - cnt);
        res = min(res, cnt);
        int op1 = 0, op2 = 0;
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                op1 += (a[i] >> j) & 1;
                op2 += ((a[i] >> j) & 1) == 0;
            }else {
                op2 += (a[i] >> j) & 1;
                op1 += ((a[i] >> j) & 1) == 0;
            }
        }
        op1 = min(op1, op2);
        res = min(res, op1);
        ans += res;
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
