#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

struct rectangle {
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    int width() { return x2 - x1; }
    int height() { return y2 - y1; }
};

void solve() {
    int W, H;
    cin >> W >> H;
    rectangle r1;
    cin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
    int w, h; cin >> w >> h;
    int ans = LLONG_MAX;    
    if (r1.width() + w <= W ) {
        ans = min(ans, max(0LL, w - r1.x1));
        ans = min(ans, max(0LL, r1.x2 - (W - w)));
    }
    if (r1.height() + h <= H ) {
        ans = min(ans, max(0LL, h - r1.y1));
        ans = min(ans, max(0LL, r1.y2 - (H - h)));
    }
    if (ans == LLONG_MAX) ans = -1;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
