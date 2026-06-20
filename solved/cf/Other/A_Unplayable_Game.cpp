#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    vector<int> a(14);
    for (int i = 0; i < 14; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < 14; ++i) {
        vector<int> b = a;
        b[i] = 0;
        for (int j = 0; j < 14; ++j) {
            b[(i + j + 1) % 14] += a[i] / 14 + (j < a[i] % 14);
        }
        int sum = 0;
        for (int j = 0; j < 14; ++j) {
            if (b[j] % 2 == 0) {
                sum += b[j];
            }
        }
        ans = max(ans, sum);
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
