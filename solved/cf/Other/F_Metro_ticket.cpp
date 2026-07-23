#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int last = -1e14;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if ((a[i] - last) * c > k + c) {
            ans += k + c;
        }else {
            ans += (a[i] - last) * c;
        }
        last = a[i];
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
