#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, c;
    cin >> n >> c;
    int ans = (c + 1) * (c + 2) / 2;
    int ev = 0, od = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ans -= (x + 2) / 2;
        ans -= c - x + 1;
        if (x % 2) ans += ++od;
        else ans += ++ev;
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
