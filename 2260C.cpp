#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int calc(int x, int y) {
    for (int i = 0; i <= x; ++i) {
        // if ((y + i) & (x - i) == 0) {
        //     return i;
        // }
        if (((y + i) ^ (x - i)) == (x + y)) {
            return i;
        }
    }
    return -1;
}

int calc2(int x, int y) {
    int sum = x + y;
    int k = 0;
    for (int i = 30; i >= 0; --i) {
        int mask = 1LL << i;
        if ((sum >> i) & 1) {
            int nx = k | mask;
            if (nx > x) continue;
            k = nx;
        }
    }
    return x - k;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int x, y;
    cin >> x >> y;
    // x = rng() % 100000 + 1;
    // y = rng() % 100000 + 1;
    int cnt = 0;
    int ans = y + x;
    // cout << calc(x, y) << " <-> ";
    // cout << calc2(x, y) << "\n";
    
    // cout << cnt << "\n";
    cout << ans << " " << calc2(x, y) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
