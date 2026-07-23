#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n * 2);
    for (auto &x : a) {
        cin >> x.first >> x.second;
    }
    sort(all(a), [](const pair<int, int> &x, const pair<int, int> &y) {
        if (x.first == y.first) return x.second > y.second;
        return (x.first + x.second) > (y.first + y.second);
    });
    int ans = 0;
    for (int i = 0; i < n; ++i) ans += a[i].first;
    for (int i = n; i < 2 * n; ++i) ans -= a[i].second;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
