#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
 
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &ai : a) cin >> ai;
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i - 1];
    int ans = 0;
    map<int,int> idx; 
    for (int i = 0; i <= n; ++i) {
        if (idx.count(pref[i] - x)) ans += idx[pref[i] - x];
        idx[pref[i]]++;
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