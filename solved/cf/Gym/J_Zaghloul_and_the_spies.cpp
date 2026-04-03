#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e6 + 5;
vector<int> divs(N + 1, 0);

void precompute() {
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            divs[j]^= i;
        }
    }
}

void solve() {
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> pref(n + 2, 0);

    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + (divs[a[i]] % k == 0);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        int ans = pref[r + 1] - pref[l];
        cout << ans << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
