#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> a(n);
    for (auto &x : a) cin >> x;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '1') {
                sum ^= ((m - j) % (k + 1));
                break;
            }
        }
    }
    // cout << sum << endl;
    cout << (sum != 0 ? "Faris" : "Hala") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
