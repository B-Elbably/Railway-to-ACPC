#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        while (x > 1) {
            if (x & 1) a[i]++;
            x >>= 1;
            a[i]++;
        }
    }
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l - 1] << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
