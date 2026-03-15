#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    
    if (n <= m) {
        cout << 1 << "\n";
        return;
    }

    int ans = 1;
    int x = n;
    while (x > m) {
        x = (x + 1) / 2;
        ans *= 2;
    }

    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
