#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int l = 0, ans = 0;
    while (l < n) {
        int r = l + 1;
        bool ok2 = (a[l] == 2); // 2 in seq?
        bool ok0 = false; // X0X in seq?
        while (l < n) {
            ok0 |= (r - l > 1 && a[r - 1] == 0);
            ok2 |= (a[r] == 2);
            bool ok = (!ok0) && (ok2 || a[l] != 0 || a[r] != 0);
            if (!ok) break;
            r++;
        }
        l = r; ans++;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
