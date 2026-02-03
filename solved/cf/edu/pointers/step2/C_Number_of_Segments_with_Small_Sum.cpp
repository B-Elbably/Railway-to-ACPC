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
    int l = 0, r = 0, sum = 0, length = 0, ans = 0;
    while (r < n) {
        sum += a[r];
        while (sum > s) {
            sum -= a[l];
            l++;
        }
        ans += r - l + 1;
        length = max(length, r - l + 1);
        r++;
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
