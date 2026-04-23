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
    for (int i = 1; i < n; ++i) {
        if (a[i] + a[i - 1] == 5) {
            cout << "Infinite";
            return;
        }
        ans += a[i] + a[i - 1];
        if (i > 1 && a[i - 2] == 3 && a[i - 1] == 1 && a[i] == 2)
            ans--;

    }
    cout << "Finite\n";
    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
