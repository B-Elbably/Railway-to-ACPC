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
    int ans = 0;
    int o = 0;
    for (int i = 1; i < n; ++i) {
        ans += (a[i] + 1 < a[i - 1]);
        o += (a[i] == a[i - 1] - 1);
    }
    cout << ans + max(0LL, o - 1) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
