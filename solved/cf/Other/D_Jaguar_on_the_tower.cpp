#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct point {
    int x, y, h;
};
int n, x, y;
__int128 dist(const point &p) {
    __int128 dx = p.x - x;
    __int128 dy = p.y - y;
    return dx * dx + dy * dy;
};

void solve() {
    cin >> n >> x >> y;
    map<pair<int, int>, vector<point>> mp;
    point pt;
    for (int i = 0; i < n; i++) {
        cin >> pt.x >> pt.y >> pt.h;
        int dx = pt.x - x;
        int dy = pt.y - y;
        int g = gcd(abs(dx), abs(dy));
        dx /= g; dy /= g;
        mp[{dx, dy}].push_back(pt);
    }
    int ans = 0;
    for (auto &[dir, v] : mp) {
        sort(v.begin(), v.end(), [&](const point &a, const point &b) {
            return dist(a) < dist(b);
        });

        int mx = -1;
        for (auto &p : v) {
            if (p.h > mx) {
                ans++;
                mx = p.h;
            }
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("jaguar.in", "r", stdin);
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
