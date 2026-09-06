#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<bool> prime(2 * n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= 2 * n; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= 2 * n; j += i)
                prime[j] = false;
        }
    }
    vector<int> a(n + 1), b(n + 1);
    iota(all(a), 0);
    int m = n;

    while (m > 1) {
        int p = 2 * m;
        while (!prime[p])
            --p;
        for (int i = p - m; i <= m; ++i)
            b[i] = p - i;
        m = p - m - 1;
    }
    b[1] = 2 - (n % 2);
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    cout << '\n';

    for (int i = 1; i <= n; ++i)
        cout << b[i] << " ";
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
