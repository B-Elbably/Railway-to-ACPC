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
    line(T a, T b, T _c) : v({b, -a}), c(-_c) {}
    // From two points P and Q
    line(pt p, pt q) : v(q - p), c(cross(v, p)) {}

    tuple<T,T,T> getEquation() const {
        T A = -v.y, B = v.x, C = -c;
        return {A, B, C};
    }

    T side(pt p) { return cross(v, p) - c; } // CW > 0, CCW < 0, on line = 0
    T dist(pt p) { return abs(side(p)) / abs(v); }
    T sqDist(pt p) { return (side(p) * side(p)) / sq(v); }
    
    line perpThrough(pt p) { return {perp(v), cross(perp(v), p)}; } // Perpendicular line through p
    pt proj(pt p) { return p - perp(v) * side(p) / sq(v); } // Projection of p onto the line
    pt refl(pt p) { return p - perp(v) * (T)2.0 * side(p) / sq(v); } // Reflection of p across the line

    line translate(pt t) { return {v, c + cross(v, t)}; } // translate line by vector t
    line shiftLeft(T dist) { return {v, c + dist * abs(v)}; } // shift line to the left by dist (looking in direction of v)
    
    static bool inter(line l1, line l2, pt &out) {
        T d = cross(l1.v, l2.v);
        if (abs(d) < EPS) return false;
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
        auto angle = [](pt p) { return atan2l(p.y, p.x); };
        T a1 = angle(v), a2 = angle(l.v);
        if (abs(a1 - a2) > EPS) return a1 < a2;
        return c < l.c;
    }
};

/** * SEGMENTS 
 */

// return true if p is in the disk with diameter ab
bool inDisk(pt a, pt b, pt p) {
    return dot(a - p, b - p) <= EPS;
}

// return true if p is on the line segment ab (including endpoints)
bool onSegment(pt a, pt b, pt p) {
    return sgn(orient(a, b, p)) == 0 && inDisk(a, b, p);
}

// True: segments ab and cd properly intersect (i.e. they share a single interior point)
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
        return a.y < b.y - EPS;
    }
};

vector<pt> segmentInter(pt a, pt b, pt c, pt d) {
    pt out;
    if (properInter(a, b, c, d, out)) return {out};
    set<pt, pt_cmp> s;
    if (onSegment(a, b, c)) s.insert(c);
    if (onSegment(a, b, d)) s.insert(d);
    if (onSegment(c, d, a)) s.insert(a);
    if (onSegment(c, d, b)) s.insert(b);
    return vector<pt>(s.begin(), s.end());
}

// distance from point p to segment ab
T distToSeg(pt a, pt b, pt p) {
    if (a == b) return abs(p - a);
    T proj_val = dot(p - a, b - a);
    if (proj_val <= 0) return abs(p - a);
    if (proj_val >= sq(b - a)) return abs(p - b);
    return abs(cross(p - a, b - a)) / abs(b - a);
}

T segTosegDist(pt a, pt b, pt c, pt d) {
    pt out;
    if (properInter(a, b, c, d, out)) return 0;
    return min({distToSeg(a, b, c), distToSeg(a, b, d),
                distToSeg(c, d, a), distToSeg(c, d, b)});
}

/** * POLYGONS 
 */
T areaPolygon(const vector<pt>& p) {
    T area = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        area += cross(p[i], p[(i + 1) % n]);
    }
    return abs(area) / 2.0;
}

bool inPolygon(const vector<pt>& p, pt a, bool strict = true) {
    int cnt = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        pt q = p[i], r = p[(i + 1) % n];
        if (onSegment(q, r, a)) return !strict;
        // Ray casting algorithm
        bool up = (q.y <= a.y && a.y < r.y);
        bool down = (r.y <= a.y && a.y < q.y);
        if ((up || down) && (a.x < (q.x - r.x) * (a.y - r.y) / (q.y - r.y) + r.x)) {
            cnt++;
        }
    }
    return cnt & 1;
}

// Triangles

T triangle_cos(pt a, pt b, pt c) {
    T ab = abs(b - a), ac = abs(c - a), bc = abs(c - b);
    return (ab * ab + ac * ac - bc * bc) / (2 * ab * ac);
}

T triangle_area(pt a, pt b, pt c) {
    return abs(cross(b - a, c - a)) / 2.0;
}
// side_a is opposite to angle_A
T triangle_area_side_angles(T side_a, T ang_A, T ang_B, T ang_C) {
    return (side_a * side_a * sin(ang_B) * sin(ang_C)) / (2 * sin(ang_A));
}

// R is the circumradius
T triangle_area_R_angles(T R, T ang_A, T ang_B, T ang_C) {
    return 2 * R * R * sin(ang_A) * sin(ang_B) * sin(ang_C);
}

void takePoint(pt &p) {
    int xx, yy; cin >> xx >> yy;
    p = {xx, yy};
}

// Distance between segments
void solve() {
    pt X, Y, Z, W;
    takePoint(X); takePoint(Y); takePoint(Z); takePoint(W);
    cout << segTosegDist(X, Y, Z, W) << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string filename;
    filename = "distance5";
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
