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
        if (x.second == y.second) return x.first < y.first;
        return x.second < y.second;
    });
    int ans = 0;
    int mx = 0;
    for (auto [x, y] : a) {
        if (x >= mx) {
            ans++;
            mx = y;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
