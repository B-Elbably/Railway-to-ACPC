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
    int ans = 1, res = 0;
    for (int i = 0; i < n - 1;++i) {
        if (a[i] == a[i + 1]) ans++;
        else ans = 1;
        res = max(res, ans);
    }
    cout << ((res >= p) ? "NO" : "YES") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
