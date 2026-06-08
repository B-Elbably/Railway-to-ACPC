#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        r[i] = a[i].second;
    }
    sort(a.begin(), a.end());
    sort(r.begin(), r.end());
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        int c = lower_bound(r.begin(), r.end(), a[i].first) - r.begin();
        int add = max(0LL, k - i + c);
        ans = (ans * add) % mod;
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
