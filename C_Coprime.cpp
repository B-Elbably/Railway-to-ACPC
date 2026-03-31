#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> idx(1001, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        idx[x] = i + 1;
    }
    int ans = 0;
    for (int i = 1; i <= 1000; ++i){
        if (!idx[i]) continue;
        for (int j = 1; j <= 1000; ++j) {
            if (!idx[j]) continue;
            if (__gcd(i, j) == 1) {
                ans = max(ans, idx[i] + idx[j]);
            }
        }
    }
    if (!ans) ans = -1;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
