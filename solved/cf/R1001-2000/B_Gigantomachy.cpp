#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    int sum1 = a[n - 1], sum2 = b[m - 1];
    for (int i = 1; i < n; i++) 
        sum1 += a[i - 1] - a[i] + 1;
    for (int i = 1; i < m; i++) sum2 += b[i - 1] - b[i] + 1;

    // cout << sum1 << " " << sum2 << endl;
    cout << (1 + (sum1 < sum2)) << endl;    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
