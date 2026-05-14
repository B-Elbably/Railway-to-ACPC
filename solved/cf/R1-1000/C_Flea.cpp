#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    int width = (m - 1) / s;
    int height = (n - 1) / s;
    int cnt1 = max(0LL, n - s * height);
    int cnt2 = max(0LL, m - s * width);
    cout << cnt1 * cnt2 * (height + 1) * (width + 1);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
