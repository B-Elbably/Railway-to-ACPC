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
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        int op1 = pref[i + 1];
        int op2 = pref[n] - pref[i + 1];
        // cout << op1 << " " << op2;
        if (op1 < op2) {
            ans = max(ans, i + 1);
        }
        if (op2 < op1) {
            ans = max(ans, n - i - 1);
        }
        // cout << "\n";
    }
    // cout << "\n";
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
