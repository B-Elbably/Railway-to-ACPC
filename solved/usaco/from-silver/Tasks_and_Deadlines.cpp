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
    sort(all(a));
    int ans = 0;
    int prefix = 0;
    for (int i = 0; i < n; i++) {
        prefix += a[i].first;
        ans += a[i].second - prefix;
    }
    cout << ans << "\n";
    // vector<int> p(n);
    // iota(p.begin(), p.end(), 0);
    // int ans = LLONG_MIN;
    // vector<int> prem;
    // do {
    //     int res = 0;
    //     int prefix = 0;
    //     for (int i : p) {
    //         prefix += a[i].first;
    //         res += a[i].second - prefix;
    //     }

    //     if (res > ans) {
    //         ans = res;
    //         prem = p;
    //     }
    // } while (next_permutation(p.begin(), p.end()));
    // cout << ans << "\n";
    // for (int i : prem) cout << i + 1 << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
