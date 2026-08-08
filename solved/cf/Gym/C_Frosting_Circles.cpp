#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct circle {
    int x, y, r;
};

void solve() {
    int n, R;
    cin >> n >> R;
    vector<circle> circles(n);
    for (auto &c : circles) {
        cin >> c.r >> c.x >> c.y;
    }
    int ans = 0;
    for (int x = -51; x <= 51; x++) {
        for (int y = -51; y <= 51; y++) {
            if (x * x + y * y > R * R) continue;
            bool ok = false;
            for (const auto &c : circles) {
                int dx = x - c.x;
                int dy = y - c.y;
                if (dx * dx + dy * dy <= c.r * c.r) {
                    ok = true;
                    break;
                }
            }
            if (ok) ans++;
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
