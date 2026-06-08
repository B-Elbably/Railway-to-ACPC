#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    int ans = 0;
    sort(all(a)); reverse(all(a));
    sort(all(b));
    for (int i = 0; i < n; ++i) {
        while (!b.empty() && b.back() > 2 * a[i]) b.pop_back();
        if (b.empty()) break;
        b.pop_back();
        ans++;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
