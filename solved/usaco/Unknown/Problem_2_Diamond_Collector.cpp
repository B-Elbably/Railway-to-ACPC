#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k, ans = 0; 
    cin >> n >> k;
    int a[n+1], pref[n+2], sz[n+2];
    pref[n] = 0;
    for(int i = 0; i < n; i++) cin >> a[i]; 
    sort(a, a+n);
    for(int i = 0; i < n; i++) sz[i] = upper_bound(a, a+n, a[i]+k) - a - i;
    for(int i = n-1; i >= 0; i--) pref[i] = max(pref[i+1], sz[i]);
    for(int i = 0; i < n; i++) ans = max(ans, sz[i] + pref[i+sz[i]]);
    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
