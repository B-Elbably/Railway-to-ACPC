#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int mn = a[i]; int mx = a[i];
        for (int j = i + 1; j < n; ++j) {
            mn = min(mn, a[j]);
            mx = max(mx, a[j]);
            sum += (mx - mn);
        }
    }
    cout << sum << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
