#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int josephus(int n, int k) {
    if (n == 1) return 1;
    if (k <= n / 2) return 2 * k;
    int x = josephus(n / 2 + n % 2, k - n / 2);
    if (n % 2 == 0) return 2 * x - 1;
    if (x == 1) return n;
    return 2 * x - 3;
}

void solve() {
    int n, k;
    cin >> n >> k;
    cout << josephus(n, k) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
