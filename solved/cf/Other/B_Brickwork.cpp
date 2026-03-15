#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    int minX = 3e18, minY = 3e18, maxX = -1, maxY = -1;
    __int128 areaSum = 0;
    set<pair<int, int>> corners;

    auto toggle = [&](int x, int y) {
        if (corners.count({x, y})) corners.erase({x, y});
        else corners.insert({x, y});
    };

    for (int i = 0; i < n; ++i) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;
        minX = min(minX, x);
        minY = min(minY, y);
        maxX = max(maxX, x + w);
        maxY = max(maxY, y + h);
        areaSum += (__int128)w * h;
        toggle(x, y);
        toggle(x + w, y);
        toggle(x, y + h);
        toggle(x + w, y + h);
    }
    __int128 Area = (__int128)(maxX - minX) * (maxY - minY);

    if (areaSum == Area &&
        corners.count({minX, minY}) && corners.count({maxX, maxY}) &&
        corners.count({minX, maxY}) && corners.count({maxX, minY})) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}