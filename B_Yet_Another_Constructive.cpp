#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m, k;
    cin >> n >> k >> m;
    vector<int> ans(n, m - 1);
    if (k > m) {
        cout << "NO" << endl;
        return;
    }
    if (m == 1) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << "1 ";
        }
        cout << endl;
        return;
    }
    cout << "YES" << endl;
    int sum = 0;
    for (int i = 0; i < k - 1; i++) sum += ans[i], sum %= m;
    // cout << ans[k-1] << " " << sum << endl;
    ans[k-1] = (m - sum) % m;
    if (ans[k-1] == 0) ans[k-1] = m;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
