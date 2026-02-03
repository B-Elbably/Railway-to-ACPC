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
    vector<int> pref(n + 1, 0), suff(n + 2, 0);
    for (int i = 1; i <= n; i++) 
        pref[i] = gcd(pref[i - 1], a[i - 1]);
    
    for (int i = n; i >= 1; i--) 
        suff[i] = gcd(suff[i + 1], a[i - 1]);  
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, gcd(pref[i - 1], suff[i + 1]));
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
