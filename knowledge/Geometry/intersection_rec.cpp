#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct rectangle
{
    int x1, y1, x2, y2;
    int area() {
        if (x1 >= x2 || y1 >= y2) return 0;
        return (x2 - x1) * (y2 - y1);
    }
};

rectangle intersect(rectangle r1, rectangle r2) {
    rectangle res;
    res.x1 = max(r1.x1, r2.x1);
    res.y1 = max(r1.y1, r2.y1);
    res.x2 = min(r1.x2, r2.x2);
    res.y2 = min(r1.y2, r2.y2);
    if (res.x1 >= res.x2 ||  res.y1 >= res.y2) {
        return {0, 0, 0, 0};
    }
    return res;
}

bool isInside(int x , int y, rectangle r) {
    // x2 <= x <= x1 and y2 <= y <= y1 
    return x >= r.x1 && x <= r.x2 && y >= r.y1 && y <= r.y2;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
