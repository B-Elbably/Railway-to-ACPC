#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int l = 0, r = 0, sum = 0, ans = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && sum < s) {
            sum += a[r];
            r++;
        }
        if (sum >= s) ans += (n - r + 1);
        sum -= a[l];
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
