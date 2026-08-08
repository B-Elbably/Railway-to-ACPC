#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int n, c;
vector<int> a;

void solve() {
    cin >> n >> c;
    a.resize(n);
    for (auto &x : a) cin >> x;
    // vector<int> l, r;
    sort(all(a));
    int ans = 0;
    int i = 0;
    for (; i < n / 2; i++) {
        if (a[i] >= c) break; 
    }
    for (; i < n; ++i) {
        ans += a[i] - c;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}

