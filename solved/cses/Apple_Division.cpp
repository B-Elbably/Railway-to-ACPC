#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int tot = 0;
    for (auto x : a) tot += x;
    int ans = tot;
    for (int i = 0 ; i < 1 << n; ++i){
        int sum = 0;
        for (int j = 0; j < n; ++j){
            if (i & (1 << j)){
                sum += a[j];
            }
        }
        ans = min(ans, abs(tot - 2 * sum));
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
