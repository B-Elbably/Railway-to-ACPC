#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> freq(n + 1, 0);
    int idx = -1;
    for (int i = 0; i < k; i++) {
        int p; cin >> p;
        freq[--p] = 1;
        if (~idx) continue;
        idx = p;
    }
    freq[n] = 1;
    int target = a[idx] ^ 1;
    int c = 0, cur = 0, mx = 0;
    for (int i = 0; i <= n; i++) {
        if (freq[i]) {
            mx = max(mx, cur);
            cur = 0;
        } else if (a[i] == target && (i == 0 || a[i - 1] != target)) {
            cur++;
            c++;
        }
    }
    cout << c << ' ' << mx << endl;
    cout << max(c, 2 * mx) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}