#include <bits/stdc++.h>
using namespace std;

#define int long long
#define X first
#define Y second

void solve() {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].X;
    for (int i = 0; i < n; i++) cin >> a[i].Y;
    sort(a.begin(), a.end()); 
    vector<int> xs;
    vector<pair<int,int>> ys;

    for (int i = 0; i < n;) {
        int x = a[i].X;
        int mn = a[i].Y, mx = a[i].Y;
        int j = i;
        while (j < n && a[j].X == x) {
            mn = min(mn, a[j].Y);
            mx = max(mx, a[j].Y);
            j++;
        }
        xs.push_back(x);
        ys.push_back({mn, mx});
        i = j;
    }

    int goDown = abs(ys[0].Y - y1) + (ys[0].Y - ys[0].X) + abs(xs[0]-x1);
    int goUp   = abs(ys[0].X - y1) + (ys[0].Y - ys[0].X) + abs(xs[0]-x1);
    for (int i = 1; i < xs.size(); i++) {
        int dx = xs[i] - xs[i-1];
        int distance = ys[i].Y - ys[i].X;
        int newDown = min(goDown + abs(ys[i-1].X - ys[i].Y), \
                            goUp   + abs(ys[i-1].Y - ys[i].Y));
        int newUp   = min(goDown + abs(ys[i-1].X - ys[i].X), \
                            goUp   + abs(ys[i-1].Y - ys[i].X));
        goDown = newDown + distance + dx;
        goUp   = newUp + distance + dx;
    }

    int ans = abs(x2 - xs.back()) +
                min(goDown + abs(ys.back().X - y2),
                    goUp + abs(ys.back().Y - y2));
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
