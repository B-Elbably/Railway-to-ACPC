#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    // vector<int> a(n);
    // for (auto &x : a) cin >> x;
    int mn = 1;
    int mx = n;
    for (int i = 0; i < n; ++i) {
        if (mx - mn > k) {
            cout << mn++ << ' ';
        }else {
            k -= (mx - mn);
            cout << mx-- << ' ';
        }
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
