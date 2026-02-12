#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());

    int l = 0, r = n - 1;
    for (int i = 0; i < n-1; i++) {
        if (i % 2 == 0) {  
            int need = (a[l+1] - a[l]) * (l+1);
            if (need > k) {
                a[l] += k/(l+1);
                break;
            }
            a[l] += a[l+1] - a[l];
            k -= need;
            l++;    
        }
        else {
            int need = (a[r] - a[r-1]) * (n-r);
            if (need > k) {
                a[r] -= k/(n-r);
                break;
            }
            k -= need;
            r--;    
        }
    }
    cout << max(0LL, a[r] - a[l]) << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
