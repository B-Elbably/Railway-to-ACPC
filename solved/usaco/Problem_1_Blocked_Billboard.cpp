#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct rectangle
{
    int x1, y1, x2, y2;
};

rectangle intersect(rectangle r1, rectangle r2)
{
    rectangle res;
    res.x1 = max(r1.x1, r2.x1);
    res.y1 = max(r1.y1, r2.y1);
    res.x2 = min(r1.x2, r2.x2);
    res.y2 = min(r1.y2, r2.y2);
    if (res.x1 >= res.x2 ||  res.y1 >= res.y2)
    {
        return {0, 0, 0, 0};
    }
    return res;
}

int get_area(rectangle r) {
    if (r.x1 >= r.x2 || r.y1 >= r.y2) return 0;
    return (r.x2 - r.x1) * (r.y2 - r.y1);
}

void solve() {
    int x11, y11, x12, y12;
    int x21, y21, x22, y22;
    int x31, y31, x32, y32;
    cin >> x11 >> y11 >> x12 >> y12;
    cin >> x21 >> y21 >> x22 >> y22;
    cin >> x31 >> y31 >> x32 >> y32;
    int area = get_area({x11, y11, x12, y12});
    area += get_area({x21, y21, x22, y22});

    area -= get_area(intersect({x11, y11, x12, y12}, {x31, y31, x32, y32}));
    area -= get_area(intersect({x21, y21, x22, y22}, {x31, y31, x32, y32}));
    cout << area << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
