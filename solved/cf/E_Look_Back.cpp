#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    ll ans = 0, cur = 0; 
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            ll need = (a[i] + a[i + 1] - 1) / a[i + 1]; 
            cur += (64 - __builtin_clzll(need - 1));   
        } else {
            ll reduce = __lg(a[i + 1] / a[i]);
            cur = max(0LL, cur - reduce);
        }
        ans += cur;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
