#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using T = double;
using pt = complex<T>;
#define x real()
#define y imag()
const T EPS = 1e-5;
const T PI = acos((T)-1.0);

struct circle {
    pt c;
    T r;
    circle(pt c = {0, 0}, T r = 0) : c(c), r(r) {}
};

vector<circle> circles;
T eval(pt p) {
    T d1 = abs(p - circles[0].c) / circles[0].r;
    T d2 = abs(p - circles[1].c) / circles[1].r;
    T d3 = abs(p - circles[2].c) / circles[2].r;
    T d12 = d1 - d2;
    T d23 = d2 - d3;
    T d31 = d3 - d1;
    return d12 * d12 + d23 * d23 + d31 * d31;
}

void solve() {
    circle c1, c2, c3;
    for (int i = 0; i < 3; i++) {
        int xx, yy, rr;
        cin >> xx >> yy >> rr;
        circles.push_back(circle(pt(xx, yy), rr));
    }
    
    double xx = (circles[0].c.x + circles[1].c.x + circles[2].c.x) / 3.0;
    double yy = (circles[0].c.y + circles[1].c.y + circles[2].c.y) / 3.0;
    T step = 1.0;
    pt center = pt(xx, yy);
    for (int i = 0; i <= (int)1e6; i++) {
        pt nxt = center;
        T mn = eval(center);
        for (T dx = -1; dx <= 1; dx++) {
            for (T dy = -1; dy <= 1; dy++) {
                pt candy = center + pt(dx, dy) * step;
                T val = eval(candy);
                if (val < mn) {
                    mn = val;
                    nxt = candy;
                }
            }
        }
        if (nxt == center) step *= 0.999;
        center = nxt;
    }
    if (eval(center) > EPS) {
        cout << endl;
        return;
    }
    cout << center.x << " " << center.y << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(5);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
