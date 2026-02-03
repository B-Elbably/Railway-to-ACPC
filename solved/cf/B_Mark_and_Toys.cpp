#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(all(a));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > p) break;
        ans++;
        p -= a[i];
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
