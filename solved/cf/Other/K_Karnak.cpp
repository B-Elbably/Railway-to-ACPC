#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    // vector<int> a(n);
    // for (auto &x : a) cin >> x;
    if (n == m) {
        cout << n - 1 << endl;
        return;
    }
    if (gcd(n, m) == 1) {
        cout << 0 << endl;
        return;
    }
    // if (n < m) {
    //     swap(n, m);
    // }
    // int ans = 0;
    // for (int i = 2; i * i <= n; i++) {
    //     if (n % i == 0) {
    //         int j = n / i;
    //         if (j < m) ans++;
    //     }
    // }
    // n / m == j / i;

    cout << gcd(n, m) - 1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
