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


int sgn(T val) { return (val > EPS) - (val < -EPS); } // compare
T sq(pt p) { return p.x * p.x + p.y * p.y; } // squared magnitude
T dot(pt v, pt w) { return v.x * w.x + v.y * w.y; } // dot product
T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; } // cross product (2D "determinant")
T orient(pt a, pt b, pt c) { return cross(b - a, c - a); } // orientation test: >0 if counter-clockwise, <0 if clockwise, =0 if collinear 

// Perpendicular vector (90 deg CCW)
pt perp(pt p) { return {-p.y, p.x}; }
bool isPerp(pt v, pt w) { return abs(dot(v, w)) < EPS; }
bool isParallel(pt v, pt w) { return abs(cross(v, w)) < EPS; }

/** * TRANSFORMATIONS 
 */
pt translate(pt p, pt v) { return p + v; } // move p by vec v;
pt scale(pt p, pt center, T factor) { return center + (p - center) * factor; }
pt rotate(pt p, pt center, T a) { // rotate p around center by angle a (in radians)
    return  center + (p - center) * polar((T)1.0, a); 
}

pt linearTransform(pt p, pt a, pt fa, pt b, pt fb) {
    // pt u = {dot(p, a) / sq(a), dot(p, b) / sq(b)};
    // return fa * u.x + fb * u.y;
    return fa + (p - a) * (fb - fa) / (b - a);
}


/** * ANGLES 
 */
T angle(pt v, pt w) { // returns angle between v and w in [0, PI]
    return acos(clamp(dot(v, w) / (abs(v) * abs(w)), (T)-1.0, (T)1.0));
}
 
// Full range [0, 2PI)
T orientedAngle(pt a, pt b, pt c) { // oriented angle from ab to ac
    T ang = angle(b - a, c - a);
    return (orient(a, b, c) >= 0) ? ang : 2 * PI - ang;
} 

T angleTraveled(pt a, pt b, pt c) { // angle traveled from ab to ac, in (-PI, PI]
    T ang = angle(b - a, c - a);
    return (orient(a, b, c) >= 0) ? ang : -ang;
}

bool inAngle(pt a, pt b, pt c, pt p) { // is p in angle abc?
    T abp = orient(a, b, p);
    T acp = orient(a, c, p);
    T abc = orient(a, b, c);
    if (abc < 0) swap(abp, acp);
    return abp >= 0 && acp <= 0;
}

/** * LINES 
 */
struct line {
    pt v; T c; 
    // From direction vector v and offset c: dot(v_perp, p) = c
    line(pt v, T c) : v(v), c(c) {}
    // From equation ax + by = c
    line(T a, T b, T _c) : v({b, -a}), c(_c) {}
    // From two points P and Q
    line(pt p, pt q) : v(q - p), c(cross(v, p)) {}

    tuple<T,T,T> getEquation() const {
        T A = -v.y, B = v.x, T, C = -c;
        return {A, B, C};
    }

    T side(pt p) { return cross(v, p) - c; } // CW > 0, CCW < 0, on line = 0
    T dist(pt p) { return abs(side(p)) / abs(v); }
    T sqDist(pt p) { return (side(p) * side(p)) / sq(v); }

    line prepThrough(pt p) { return {perp(v), cross(perp(v), p)}; } // Perpendicular line through p
    pt proj(pt p) { return p - perp(v) * side(p) / sq(v); } // Projection of p onto the line
    pt refl(pt p) { return p - perp(v) * (T)2.0 * side(p) / sq(v); } // Reflection of p across the line

    line translate(pt t) { return {v, c + cross(v, t)}; } // translate line by vector t
    line shiftLeft(T dist) { return {v, c + dist * abs(v)}; } // shift line to the left by dist (looking in direction of v)
    bool inter(line l1, line l2, pt &out) {
        T d = cross(l1.v, l2.v);
        if (fabs(d) < EPS) return false;
        out = (l2.v * l1.c - l1.v * l2.c) / d;
        return true;
    }

    // return the bisector of the angle between l1 and l2, interior=true for interior bisector, false for exterior
    line bisector(line l1, line l2, bool interior) {
        assert(fabsl(cross(l1.v, l2.v)) > EPS); // l1 and l2 should not be parallel
        T sign = (interior ? 1 : -1);
        return { l2.v / abs(l2.v) + sign * l1.v / abs(l1.v),
                l2.c / abs(l2.v) + sign * l1.c / abs(l1.v) };
    }


    bool cmpProj(pt p, pt q) { // compare projections of p and q on the line, for sorting points along the line
        return dot(v, p) < dot(v, q);
    }

    bool operator < (const line& l) const { // sort by angle, then by distance from origin
        if (sgn(v.y) != 0) return sgn(v.y) < 0;
        if (sgn(v.x) != 0) return sgn(v.x) < 0;
        return c < l.c;
    }
};

void takePoint(pt &p) {
    int xx, yy; cin >> xx >> yy;
    p = {xx, yy};
}   

void solve() {
    pt X, Y, Z;
    takePoint(X); takePoint(Y); takePoint(Z);
    line XY(X, Y), XZ(X, Z);
    line bis = XY.bisector(XY, XZ, true);
    T A, B, C; tie(A, B, C) = bis.getEquation();
    cout << A << " " << B << " " << C << "\n";
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string filename;
    filename = "bisector"; 
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