#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int cnt = 0, l = 0, r = 0, ans = 0;
    vector<int> used(1e5 + 5, 0);
    while (r < n) {
        if (used[a[r]] == 0) cnt++;
        used[a[r]]++;
        while (cnt > x) {
            used[a[l]]--;
            if (used[a[l]] == 0) cnt--;
            l++;
        }
        ans += r - l + 1;
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
