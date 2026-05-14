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

T dot(pt v, pt w) { return v.x * w.x + v.y * w.y; } // dot product
T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; } // cross product (2D "determinant")
T orient(pt a, pt b, pt c) { return cross(b - a, c - a); } // orientation test: >0 if counter-clockwise, <0 if clockwise, =0 if collinear 

T angle(pt v, pt w) { // returns angle between v and w in [0, PI]
    return acos(clamp(dot(v, w) / (abs(v) * abs(w)), (T)-1.0, (T)1.0));
}
 
// Full range [0, 2PI)
T orientedAngle(pt a, pt b, pt c) { // oriented angle from ab to ac
    T ang = angle(b - a, c - a);
    return (orient(a, b, c) >= 0) ? ang : 2 * PI - ang;
} 


void takePoint(pt &p) {
    int xx, yy; cin >> xx >> yy;
    p = {xx, yy};
}

void solve() {
    pt p1;
    takePoint(p1);
    cout << orientedAngle({0, 0}, {1, 0}, p1) << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string filename;
    filename = "angle1";
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