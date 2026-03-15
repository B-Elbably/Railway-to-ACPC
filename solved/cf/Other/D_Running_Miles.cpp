#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), suff(n + 2, LLONG_MIN), pref(n + 1, LLONG_MIN);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        suff[i] = a[i] - i;
        pref[i] = a[i] + i;
    }
    for (int i = 1; i <= n; ++i)
        pref[i] = max(pref[i], pref[i - 1]);
    
    for (int i = n - 1; i >= 0; --i) 
        suff[i] = max(suff[i], suff[i + 1]);
    
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        ans = max(ans, pref[i - 1] + a[i] + suff[i + 1]);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t; 
    while (t--) solve();
}
