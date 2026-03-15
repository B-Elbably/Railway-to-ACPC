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
    for (int i = 0; i < n - 1; i++) {
        ans += a[i + 1] - a[i];
    }
    for (int i = n - 1; i > 0; i--) {
        ans -= a[i] - a[i - 1];
    }
    ans -= a[n - 1];
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}


