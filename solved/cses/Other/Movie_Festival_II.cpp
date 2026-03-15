#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i].first >> a[i].second;
    sort(all(a), [](auto &x, auto &y) {
        return x.second < y.second;
    });
    int ans = 0;
    multiset<int> s;
    for (int i = 0; i < k; i++) s.insert(0);
    for (int i = 0; i < n; i++) {
        auto it = s.upper_bound(a[i].first);
        if (it == s.begin()) continue;
        it--;
        s.erase(it);
        ans++;
        s.insert(a[i].second);
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
