#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int d = n - k;

    for (int i = 0; (1 << i) <= d; ++i) {
        if (((d >> i) & 1) == 0) continue;  
        int shift = 1 << i;
        for (int j = 0; j < n - shift; ++j) {
            a[j] ^= a[j + shift];   
        }
        n -= shift;
    }
    for (int i = 0; i < k; ++i) {
        cout << a[i] << ' ';
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
