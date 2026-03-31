#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int m; cin >> m;
    int n = 0;
    for (int i = m; i >= 0; --i) {
        int ai; cin >> ai; 
        if (!ai) continue;       
        n += pow(2, i);
    }
    int ans = 0;
    while (n > 1) {
        int p2 = n << 1; p2 += 1;
        if (n & 1) {
            n ^= p2;
            ans++;
        }
        while (n % 2 == 0) {
            n /= 2;
            ans++;
        }
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
