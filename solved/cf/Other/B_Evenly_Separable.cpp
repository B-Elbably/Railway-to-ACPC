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
    vector<int> pref(n + 1), suf(n + 1);
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i - 1];
    for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i];
    // for (int x: pref) cout << x << " ";
    // cout << endl;
    // for (int x: suf) cout << x << " ";
    // cout << endl;
    int ans = LLONG_MAX;
    for (int i = 1; i < n; ++i) {
        int op1 = pref[i] - suf[i];
        int op2 = n - 2 * i;
        if (!op1 && !op2) ans = min(ans, 0LL);
        if (!op2) continue;
        // if (op1 > 0) break;
        if (op1 % op2) continue;
        int x = op1 / op2;
        if (x < 0) continue;
        if (pref[i] + x * i == (n - i) * x + suf[i]) 
            ans = min(ans, x);
    }
    if (ans > (int)1e18) ans = -1;
    cout << ans << "\n";
} 

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
