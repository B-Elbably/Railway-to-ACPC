#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using T = long double;
const T PI = acos(-1.0);

pair<int, int> slope(int x, int y) {
    int g = __gcd(abs(x), abs(y));
    x /= g; 
    y /= g;
    if (x < 0 || (x == 0 && y < 0)) {
        x = -x;
        y = -y;
    }
    return {x, y};
}   

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        map<pair<int, int>, int> mp;
        for (int j = i + 1; j < n; ++j) {
            int x = a[j].first - a[i].first;
            int y = a[j].second - a[i].second;
            mp[slope(x, y)]++;
        }
        for (const auto& [s, cnt] : mp) {
            ans += cnt * (cnt - 1)  * (cnt - 2) / 6;
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
    return 0;
}
