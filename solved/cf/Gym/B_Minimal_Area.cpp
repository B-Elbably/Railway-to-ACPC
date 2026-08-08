#include <bits/stdc++.h>
using namespace std;

/** * BASIC SETUP & UTILS 
 */
using T = long long;
using pt = complex<T>;

#define x real()
#define y imag()

const T EPS = 1e-9;
const T PI = acos((T)-1.0);

int sgn(T val) { return (val > EPS) - (val < -EPS); } // compare with tolerance
T sq(pt p) { return p.x * p.x + p.y * p.y; } // squared magnitude
T dot(pt v, pt w) { return v.x * w.x + v.y * w.y; } // dot product
T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; } // cross product (2D "determinant")
T orient(pt a, pt b, pt c) { return cross(b - a, c - a); } // >0 CCW, <0 CW, =0 collinear 

// Perpendicular vector (90 deg CCW)
pt perp(pt p) { return {-p.y, p.x}; }
bool isPerp(pt v, pt w) { return abs(dot(v, w)) < EPS; }
bool isParallel(pt v, pt w) { return abs(cross(v, w)) < EPS; }

bool angleCompare(pt a, pt b) {
    return atan2(a.y, a.x) < atan2(b.y, b.x);
}

void rotatePoint(double &x, double &y, double theta) {
    double nx = x * cos(theta) - y * sin(theta);
    double ny = x * sin(theta) + y * cos(theta);
    x = nx;
    y = ny;
}

/** * TRANSFORMATIONS 
 */
pt translate(pt p, pt v) { return p + v; } // move p by vec v
pt scale(pt p, pt center, T factor) { return center + (p - center) * factor; }
pt rotate(pt p, pt center, T a) { // rotate p around center by angle a (in radians)
    return center + (p - center) * polar((T)1.0, a); 
}

pt linearTransform(pt p, pt a, pt fa, pt b, pt fb) {
    return fa + (p - a) * (fb - fa) / (b - a);
}

/** * ANGLES 
 */
T angle(pt v, pt w) {
    if (abs(v) < EPS || abs(w) < EPS) return 0; // Guard against zero vectors
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

bool inAngle(pt a, pt b, pt c, pt p) { // is p in angle bac (including boundary)
    T abp = orient(a, b, p);
    T acp = orient(a, c, p);
    T abc = orient(a, b, c);
    if (abs(abc) < EPS) return sgn(dot(b - a, p - a)) >= 0 && sgn(dot(c - a, p - a)) >= 0;
    if (abc < 0) swap(abp, acp);
    return (abp >= -EPS && acp <= EPS) ^ (abc < -EPS);
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
        return {-v.y, v.x, -c};
    }

    T side(pt p) { return cross(v, p) - c; } // CW > 0, CCW < 0, on line = 0
    T dist(pt p) { return abs(side(p)) / abs(v); }
    T sqDist(pt p) { return (side(p) * side(p)) / sq(v); }
    
    line perpThrough(pt p) { return {perp(v), cross(perp(v), p)}; } // Perpendicular through p
    pt proj(pt p) { return p - perp(v) * side(p) / sq(v); } // Projection onto line
    pt refl(pt p) { return p - perp(v) * (T)2.0 * side(p) / sq(v); } // Reflection across line

    line translate(pt t) { return {v, c + cross(v, t)}; } // translate by vector t
    line shiftLeft(T dist) { return {v, c + dist * abs(v)}; } // shift left by dist 

    static bool inter(line l1, line l2, pt &out) {
        T d = cross(l1.v, l2.v);
        if (abs(d) < EPS) return false;
        out = (l2.v * l1.c - l1.v * l2.c) / d; 
        return true;
    }

    // bisector of angle between l1 and l2 (interior=true for interior bisector)
    static line bisector(line l1, line l2, bool interior) {
        T sign = interior ? 1 : -1;
        pt v1 = l1.v / abs(l1.v);
        pt v2 = l2.v / abs(l2.v);
        pt res_v = v2 + v1 * sign;        
        if (abs(res_v) < EPS) res_v = perp(l1.v);
        pt intersection;
        if (!line::inter(l1, l2, intersection)) {
            if (dot(v1, v2) < 0) l2.c = -l2.c;
            return {l1.v, (l1.c + l2.c) / (T)2.0};
        }
        return {res_v, cross(res_v, intersection)};
    }

    bool cmpProj(pt p, pt q) { // compare projections of p and q on the line
        return dot(v, p) < dot(v, q);
    }
    
    bool operator < (const line& l) const { // sort by angle, then distance from origin
        // Use generic atan2 instead of atan2l to support any type T
        auto ang = [](pt p) { return atan2(p.y, p.x); };
        T a1 = ang(v), a2 = ang(l.v);
        if (abs(a1 - a2) > EPS) return a1 < a2;
        return c < l.c;
    }
};

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

// return set of all intersections between segments ab and cd (0, 1, or 2 points)
struct pt_cmp {
    bool operator()(const pt& a, const pt& b) const {
        if (abs(a.x - b.x) > EPS) return a.x < b.x;
        if (abs(a.y - b.y) > EPS) return a.y < b.y;
        return false; // Equal within EPS
    }
};

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
    int n; cin >> n;
    vector<pt> polygon(n);
    for (int i = 0; i < n; i++) {
        takePoint(polygon[i]);
    }
    long long ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        pt a, b, c;
        a = polygon[i];
        b = polygon[(i + 1) % n];
        c = polygon[(i + 2) % n];
        ans = min(ans, (long long)abs(cross(b - a, c - a)));
    }
    cout << ans<< "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string filename;
    // filename = "";
    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
    // cout << fixed << setprecision(10);
    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}