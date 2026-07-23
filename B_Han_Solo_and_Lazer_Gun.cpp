#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, x0, y0;
    cin >> n >> x0 >> y0;
    int ans = 0;
    set<pair<int, int>> st;
    int bad = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        int dx = x - x0;
        int dy = y - y0;
        int g = gcd(abs(dx), abs(dy));
        dx /= g;
        dy /= g;
        if (dx < 0) {
            dx = -dx;
            dy = -dy;
        }
        if (dx == 0) dy = 1;
        if (dy == 0) dx = 1;
        st.insert({dx, dy});
    }
    cout << st.size() << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
