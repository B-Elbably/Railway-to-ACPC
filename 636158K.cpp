#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    vector<pair<int, int>> bad;
    vector<int> ans(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    for (int i = 0; i < n; ++i) {
        // if i > ai && i <= bi , get bad
        // if i > b[i] cancel
        // cout << b[i] << " ";
        if (b[i] > a[i]) {
            bad.push_back({b[i] - a[i], i});
        }else {
            ans[i] = b[i];
        }
    }
    sort(all(bad));
    reverse(all(bad));
    for (int i = 0; i < k; ++i) {
        ans[bad[i].second] = b[bad[i].second];
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i] == 0) {
            ans[i] = a[i];
        }
    }
    for (int x: ans) cout << x << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
