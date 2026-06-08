#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int PI = acos(-1);

void solve() {
    int r, deg;
    cin >> r >> deg;
    int cnt = 360 / deg;
    if (cnt & 1) {
        cout << "NO" << endl;
        return;
    }
    cout << ((cnt * deg == 360) ? "YES" : "NO") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
