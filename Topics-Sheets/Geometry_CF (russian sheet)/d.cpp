#include <bits/stdc++.h>
using namespace std;

/** * BASIC SETUP & UTILS 
 */
using T = long double;
using pt = complex<T>;

#define x real()
#define y imag()

const T EPS = 1e-9;
const T PI = acos((T)-1.0);

T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; } // cross product (2D "determinant")

T triangle_area(pt a, pt b, pt c) {
    return abs(cross(b - a, c - a)) / 2.0;
}

void takePoint(pt &p) {
    int xx, yy; cin >> xx >> yy;
    p = {xx, yy};
}

void solve() {
    pt p1, p2, p3;
    takePoint(p1); takePoint(p2); takePoint(p3);
    cout << triangle_area(p1, p2, p3);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string filename;
    // filename = "area1";
    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
    cout << fixed << setprecision(10);
    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
} 