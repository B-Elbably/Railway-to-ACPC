#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

pair<int, int> slope(int x, int y) {
    // int g = __gcd(x, y);
    // x /= g;
    // y /= g;
    // if (y < 0) {
    //     x = -x;
    //     y = -y;
    // }
    // if (x == 0) y = 1;
    // if (y == 0) x = 1;
    return {x, 0};
}

void solve() {
    int n;
    cin >> n;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mp[slope(x, y)]++;
    }   
    int ans = 0;
    for (auto [s, x] : mp) {
        // int x = n - c;
        ans += x * (n - x);
    }
    cout << ans / 2 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
