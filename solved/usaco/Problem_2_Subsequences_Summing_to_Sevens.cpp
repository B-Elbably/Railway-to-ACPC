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
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i) pref[i] = (pref[i - 1] + a[i - 1]) % 7;
    int ans = 0;
    map<int,int> idx; 
    for (int i = 1; i <= n; ++i) {
        if (idx.count(pref[i])) ans = max(ans, i - idx[pref[i]]);
        else idx[pref[i]] = i; 
    } 
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
