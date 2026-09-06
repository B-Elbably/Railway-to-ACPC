#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using T = long double;
using pt = complex<T>;
#define x real()
#define y imag()

const T EPS = 1e-9;
const T PI = acos((T)-1.0);


struct circle {
    pt c; T r;

    circle(pt center = pt(0, 0), T radius = 0) : c(center), r(radius) {}

    T area() const {
        return PI * r * r;
    }

    T circumference() const {
        return 2 * PI * r;
    }

    bool contains(pt p) const {
        return abs(p - c) <= r + EPS;
    }
    T intersection_area(circle other) const {
        T d = abs(other.c - c);
        if (d >= r + other.r - EPS) return 0;
        if (d <= abs(r - other.r) + EPS) return PI * min(r, other.r) * min(r, other.r);
        
        T a1 = acos(clamp((r * r + d * d - other.r * other.r) / (2 * r * d), (T)-1.0, (T)1.0));
        T a2 = acos(clamp((other.r * other.r + d * d - r * r) / (2 * other.r * d), (T)-1.0, (T)1.0));
        return r * r * a1 + other.r * other.r * a2 - r * d * sin(a1);
    }
    bool touch(circle other) const {
        T d = abs(other.c - c);
        return abs(d - (r + other.r)) < EPS || abs(d - abs(r - other.r)) < EPS;
    }

    bool contains(circle other) const {
        T d = abs(other.c - c);
        return d + other.r <= r + EPS;
    }

    bool intersect(circle other) const {
        T d = abs(other.c - c);
        return d < r + other.r + EPS && d > abs(r - other.r) - EPS;
    }

};

void solve() {
    circle c1, c2;
    int xx, yy, r;
    cin >> xx >> yy >> r;
    c1 = circle(pt(xx, yy), r);
    cin >> xx >> yy >> r;
    c2 = circle(pt(xx, yy), r);

    T inter = c1.intersection_area(c2);
    T area1 = c1.area();
    T area2 = c2.area();
    if (c1.c.x == c2.c.x && c1.c.y == c2.c.y && c1.r == c2.r) {
        cout << -1 << endl;
        return;
    }
    if (c1.contains(c2) || c2.contains(c1)) {
        if (c1.touch(c2)) {
            T ans = area1 - area2;
            if (ans < 0) ans = -ans;
            cout << fixed << setprecision(10) << ans << endl;
        }else {
            cout << -1 << endl;
        }
        return;
    }
    if (!c1.intersect(c2)) {
        cout << -1 << endl;
    }else {
        T ans = max({area1 - inter, area2 - inter});
        cout << fixed << setprecision(10) << ans << endl;
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
