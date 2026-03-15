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
    int ans = LLONG_MAX;
    for (int i = 0; i < n; ++i){
        int res = 0;
        for (int j = 0; j < n - 1; ++j){
            res += (j + 1) * a[(i + j) % n];
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
