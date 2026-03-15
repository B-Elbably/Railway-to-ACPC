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
    vector<pair<int, int>> stops;
    for (int i = 0; i < n - 2; i++) {
        stops.push_back({a[i + 2] - a[i], i + 1});
    }
    sort(all(stops));
    vector<int> b;
    for (int i = 0; i < n; i++) {
        if (i == stops[0].second) continue;
        b.push_back(a[i]);
    }
    int ans = 0;
    for (int i = 1; i < b.size(); i++) {
        ans = max(ans, b[i] - b[i - 1]);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
