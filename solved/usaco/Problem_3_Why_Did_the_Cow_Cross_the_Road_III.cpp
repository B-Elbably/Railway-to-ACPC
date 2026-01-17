#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a) cin >> x.first >> x.second;
    sort(all(a), compare);
    int ans = a[0].first + a[0].second;
    for (int i = 1; i < n; ++i) {
        if (a[i].first > ans) {
            ans = a[i].first + a[i].second;
        } else {
            ans += a[i].second;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
