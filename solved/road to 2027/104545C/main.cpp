#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }

    int ans = 0;

    for (int mid = 1; mid <= n * m; mid++) {
        // int m = (l + r) / 2;
        bool ok = false;
        vector<int> divs1;
        for (int i = 1; i * i <= mid; i++) { 
            if (mid % i) continue;
            divs1.push_back(i);
            divs1.push_back(mid / i);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int x1 = i, y1 = j;
                for (int k = 0; k < (int)divs1.size(); k++) {
                    int x2 = x1 + divs1[k] - 1;
                    int y2 = y1 + (mid / divs1[k]) - 1;
                    if (x2 > n || y2 > m) continue;
                    int sum = a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
                    // cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << sum << endl;
                    // cout << i << ' ' << j << ' ' << divs1[k] << ' ' << mid / divs1[k] << ' ' << sum << endl;
                    if (sum == mid) {
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }
            if (ok) break;
        }
        if (ok) {
            ans = mid;
        }
    }
    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
