#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int x, y;
    cin >> x >> y;
    int xs = 0;
    if (y < 0) {
        xs = -y * 4;
    } else {
        xs = y * 2;
    }
    if (xs > x) {
        cout << "NO" << endl;
        return;
    }
    x -= xs;
    cout << ((x % 3 == 0) ? "YES" : "NO") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
