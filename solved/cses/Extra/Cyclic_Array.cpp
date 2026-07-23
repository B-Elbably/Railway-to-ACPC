#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    int r = 0, sum = 0;
    vector<vector<int>> up(2 * n + 1, vector<int>(20, 2 * n));
    for (int l = 0; l < 2 * n; l++) {
        while (r < 2 * n && r - l < n && sum + a[r] <= k) {
            sum += a[r++];
        }
        up[l][0] = r;
        if (l < r) sum -= a[l];
        else r = l + 1;
    }
    up[2 * n][0] = 2 * n;
    for (int j = 1; j < 20; j++) {
        for (int i = 0; i < 2 * n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    int ans = n;
    for (int s = 0; s < n; s++) {
        int cur = s;
        int cnt = 0;
        for (int j = 19; j >= 0; j--) {
            if (up[cur][j] < s + n) {
                cur = up[cur][j];
                cnt += (1 << j);
            }
        }
        ans = min(ans, cnt + 1);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
