#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n; cin >> n;
    int l = 0, r = n - 1;
    int lx = n;

    while (l <= r) {
        int m = (l + r) / 2;
        int resp1, resp2;

        cout << "1 1 " << m + 1 << endl;
        cin >> resp1;
        cout << "2 1 " << m + 1 << endl;
        cin >> resp2;

        if (resp1 != resp2) {
            lx = m + 1;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << "2 1 " << n << endl;
    int sum; cin >> sum;
    sum -= (n * (n + 1) / 2);
    cout << "! " << lx << " " << lx + sum - 1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}