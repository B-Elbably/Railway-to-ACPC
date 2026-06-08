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
    sort(all(a));
    int ans = n;
    for(int i = 0; i < n; i++) {
        int mn = lower_bound(all(a),a[i]) - a.begin();
        int mx = upper_bound(all(a),a[i]) - a.begin();
        ans = min(ans, max(mn,n - mx));
    }
    cout << ans << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
