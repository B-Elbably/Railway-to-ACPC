#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    vector<vector<int>> a(m , vector<int>(n)), prefix(m , vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[j][i];
        }
    }
    
    for (int i = 0; i < m; ++i) {
        sort(all(a[i]));
        prefix[i][0] = a[i][0];
        for (int j = 1; j < n; ++j) {
            prefix[i][j] = prefix[i][j - 1] + a[i][j];
        }
    }
    for (int i = 0; i < m ; ++i) {
        for (int j = 0; j < n; ++j ) {
            ans += prefix[i][n - 1] - prefix[i][j] - (n - 1 - j) * a[i][j];
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}

// 1 3 7 10
// 1 4 11 21
// 3 - 1 + 7 - 1 + 10 - 1 = 17 = (21 - 1) - (3 * 1)
// 7 - 3 + 10 - 3 = 11 = (21 - 4) - (3 * 2)