#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a) cin >> x.first >> x.second;
    sort(all(a), [](const pair<int, int> &x, const pair<int, int> &y) {
        return (x.first - x.second) > (y.first - y.second);
    });
    int ans = 0;
    int last = 0;
    for (auto [x, y] : a) {
        ans += max(0LL, x - last);
        if (last < x) last = x; 
        last -= y; 
    }
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
