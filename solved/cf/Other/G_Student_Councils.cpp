#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int k; cin >> k;
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int l = 0, r = 1e18;
    while (l <= r) {
        int mid = (l + r) / 2;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += min(mid, a[i]);
        }
        if (sum / mid < k) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << max(0LL, --l) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
