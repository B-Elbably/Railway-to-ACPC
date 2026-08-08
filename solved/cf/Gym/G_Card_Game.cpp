#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> pref(n + 1);
    for (int i = 2; i <= n; ++i) {
        pref[i] = (i) * (i - 1) / 2;
        pref[i] += pref[i - 1];
    }
    double ans = 2 * (double)pref[n] / n;
    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
