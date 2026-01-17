#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define endl '\n'


void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    for (int i = 0; i < n; ++i) a[i] *= (i + 1) * (n - i);
    
    sort(all(a)); sort(allr(b));
    int ans = 0;
    for (int i = 0; i < n;++i) ans += a[i] * b[i];
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
