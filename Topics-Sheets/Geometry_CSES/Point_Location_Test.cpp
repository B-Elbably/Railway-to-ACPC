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

int sgn(T val) { return (val > EPS) - (val < -EPS); } // compare with tolerance
T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; } // cross product (2D "determinant")
T orient(pt a, pt b, pt c) { return cross(b - a, c - a); } // >0 CCW, <0 CW, =0 collinear 

void takePoint(pt &p) {
    T xx, yy; cin >> xx >> yy;
    p = pt(xx, yy);
}

void solve() {
    pt X, Y, Z;
    takePoint(X); takePoint(Y); takePoint(Z);
    int ss = sgn(orient(X, Y, Z));
    vector<string> pos = {"RIGHT", "TOUCH", "LEFT"};
    cout << pos[ss + 1] << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string filename;
    // filename = "";
    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
    cout << fixed << setprecision(10);
    int t = 1; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}