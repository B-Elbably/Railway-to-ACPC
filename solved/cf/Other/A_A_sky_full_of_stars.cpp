#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct pt {
    int x, y;
};

int dot(pt v, pt w) { return v.x * w.x + v.y * w.y; }

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    l *= 2;
    r *= 2;
    vector<pt> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int dx = a[i].x - a[j].x;
            int dy = a[i].y - a[j].y;
            for (int k = j + 1; k < n; ++k) {
                if (k == i || k == j) continue;
                int dx2 = a[i].x - a[k].x;
                int dy2 = a[i].y - a[k].y;
                int d = dot({dx, dy}, {dx2, dy2});
                if (d != 0) continue;
                int area = abs(dx * dy2 - dy * dx2);
                if (area >= l && area <= r) ans++;
            }
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("points.in", "r", stdin);
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
