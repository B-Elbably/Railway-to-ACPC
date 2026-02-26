#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    int l = 1, r = n * n;
    while(l < r) {
        int m = l + (r - l) / 2, count = 0;
        for (int i = 1; i <= n; i++) {
            count += min(n, m / i);
        }
        if (count < (n * n + 1) / 2) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << l << endl;
}   

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}

// 1 3 5 7  9  11 13
// 1 3 8 12 20 28 39