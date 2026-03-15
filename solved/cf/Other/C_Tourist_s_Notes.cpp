#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> d(q), h(q);
    int ans = 0;
    for (int i = 0; i < q; i++) {
        cin >> d[i] >> h[i];
        ans = max(ans, h[i]);
    }
    for (int i = 0; i < q - 1; ++i) {
        if (abs(h[i] - h[i+1]) > d[i+1] - d[i]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        ans = max(ans, (d[i+1] - d[i] + h[i] + h[i+1]) / 2);
    }
    
    ans = max(ans, h[0] + d[0] - 1);
    ans = max(ans, h[q-1] + n - d[q-1]);
    
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}