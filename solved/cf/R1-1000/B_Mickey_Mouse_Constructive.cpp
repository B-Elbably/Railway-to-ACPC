#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int count_divisors(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            cnt++;
            if (i * i != n) {
                cnt++;
            }
        }
    }
    return cnt % 676767677;
}

void solve() {
    int x, y;
    cin >> x >> y;
    if (x == y) {
        cout << 1 << endl;
    } else {
        cout << count_divisors(abs(x - y)) << endl;
    }
    
    for (int i = 0; i < x; ++i) cout << 1 << " ";
    for (int i = 0; i < y; ++i) cout << -1 << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
