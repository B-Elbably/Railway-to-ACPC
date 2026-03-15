#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int M = 1e9 + 7;
const int inv2 = 500000004;

int range_sum(int l, int r) {
    // l + (l+1) + ... + r = (l + r) * (r - l + 1) / 2
    int term1 = (l + r) % M;
    int term2 = (r - l + 1) % M;
    return (((term1 * term2) % M) * inv2) % M;
}

void solve() {
    int n;
    cin >> n;
    int ans = 0;

    for (int l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l); 
        int count = (n / l) % M;
        int sum = range_sum(l, r);
        ans = (ans + (count * sum) % M) % M;
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
