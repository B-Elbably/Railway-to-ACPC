#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ans = 0;
    // sort(all(a));
    int i = 0, j = 0; 
    int sum = 0;
    for (;j < n; j++) {
        sum += a[j];
        while (sum > w) {
            sum -= a[i];
            i++;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
