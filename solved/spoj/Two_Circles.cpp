#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using T = long double;
const T EPS = 1e-9;
const T PI = acos(-1.0);
using pt = complex<T>;

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
    circle a, b;
    int xx, yy, r;
    cin >> xx >> yy >> r;
    a = circle(pt(xx, yy), r);
    cin >> xx >> yy >> r;
    b = circle(pt(xx, yy), r);
    T d = abs(a.c - b.c);

    if (abs(d - abs(a.r - b.r)) <= EPS) {
        cout << "E" << endl;
    } else if (a.contains(b) || b.contains(a)) {
        cout << "I" << endl;
    } else {
        cout << "O" << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
