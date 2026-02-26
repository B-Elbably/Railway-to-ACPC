#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int l = *max_element(all(a)), r = 1e18 + 5;
    while (l < r) {
        int m = l + (r - l) / 2;
        int parts = 0, cnt = 0;
        for (auto x : a) {
            if (cnt + x <= m) cnt += x;
            else {
                parts++;
                cnt = x;
            }
        }
        if (cnt > 0) parts++;
        if (parts <= k) r = m;
        else l = m + 1;
    }
    cout << l << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
