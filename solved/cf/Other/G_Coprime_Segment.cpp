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
    vector<pair<int,int>> prev, cur;
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        cur.clear();
        cur.push_back({a[i], 1});
        for (auto [g, len] : prev) {
            int gc = gcd(g, a[i]);
            if (cur.back().first == gc)
                cur.back().second = min(cur.back().second, len + 1);
            else
                cur.push_back({gc, len + 1});
        }
        for (auto [g, len] : cur)
            if (g == 1) ans = min(ans, len);
        prev = cur;
    }
    if (ans == 1e9) cout << -1;
    else cout << ans;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}

