#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &X : a) {
        int x, y; cin >> x >> y;
        X = {x - y, x + y};
    }
    sort(all(a), [](const pair<int, int> &p1, const pair<int, int> &p2) {
        if (p1.first == p2.first) return p1.second > p2.second;
        return p1.first < p2.first;
    });
    int ans = n, mx = a[0].second;
    for (int i = 1; i < n; ++i) {
        if (a[i].second <= mx) ans--;
        else mx = a[i].second;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
