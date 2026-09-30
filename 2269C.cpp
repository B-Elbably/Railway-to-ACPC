#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int sum = 0;
    for (auto &x : a) cin >> x, sum += x;
    if (k == 1) {
        cout << sum << endl;
        return;
    }
    int lim = min(k - 1, n - k + 1);
    // cout << lim << endl;
    for (int i = 0; i < lim; ++i) {
        sum -= min(a[i], a[n - i - 1]);
    }

    if (lim == k - 1) {
        cout << sum << endl;
        return;
    }
    // cout << sum << endl;
    if (lim != k - 1) {
        for (int i = lim; i < n - lim; ++i) {
            sum -= a[i];
        }
    }
    cout << sum  << endl   ;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
