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
T dot(pt v, pt w) { return v.x * w.x + v.y * w.y; } // dot product
T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; } // cross product (2D "determinant")
T orient(pt a, pt b, pt c) { return cross(b - a, c - a); } // >0 CCW, <0 CW, =0 collinear 

/** * SEGMENTS 
 */
bool inDisk(pt a, pt b, pt p) { // true if p is in disk with diameter ab
    return dot(a - p, b - p) <= EPS;
}

bool onSegment(pt a, pt b, pt p) { // true if p is on segment ab (inclusive)
    return sgn(orient(a, b, p)) == 0 && inDisk(a, b, p);
}

// True: segments ab and cd properly intersect (share a single interior point)
bool properInter(pt a, pt b, pt c, pt d, pt &out) {
    T oa = orient(c, d, a), ob = orient(c, d, b);
    T oc = orient(a, b, c), od = orient(a, b, d);
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0) {
        out = (a * ob - b * oa) / (ob - oa);
        return true;
    }
    return false;
}


vector<pt> segmentInter(pt a, pt b, pt c, pt d) {
    pt out;
    if (properInter(a, b, c, d, out)) return {out};
    vector<pt> s, res;
    if (onSegment(a, b, c)) s.push_back(c);
    if (onSegment(a, b, d)) s.push_back(d);
    if (onSegment(c, d, a)) s.push_back(a);
    if (onSegment(c, d, b)) s.push_back(b);
    for (pt p : s) {
        bool dup = false;
        for (pt r : res) if (abs(p - r) < EPS) dup = true;
        if (!dup) res.push_back(p);
    }
    return res;
}

void takePoint(pt &p) {
    T xx, yy; cin >> xx >> yy;
    p = pt(xx, yy);
}

void solve() {
    pt X, Y, Z, W;
    takePoint(X); takePoint(Y); takePoint(Z); takePoint(W);
    vector<pt> intersections = segmentInter(X, Y, Z, W);
    cout << (intersections.empty() ? "NO" : "YES") << "\n";
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