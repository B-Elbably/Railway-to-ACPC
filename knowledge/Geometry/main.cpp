#include <bits/stdc++.h>
using namespace std;

/** * BASIC SETUP & TYPES 
 */
using T = long double;
using pt = complex<T>;

#define x real()
#define y imag()

const T EPS = 1e-9;
const T PI = acos((T)-1.0);

// usecase: Check sign of floating point value with EPS tolerance.
// returns: 1 if positive, -1 if negative, 0 if zero (within EPS).
int sgn(T val) { return (val > EPS) - (val < -EPS); }

// usecase: Compute squared magnitude of vector p (avoiding sqrt for speed).
// returns: p.x^2 + p.y^2.
T sq(pt p) { return p.x * p.x + p.y * p.y; }

// usecase: Compute standard dot product of vectors v and w.
// returns: v.x * w.x + v.y * w.y.
T dot(pt v, pt w) { return v.x * w.x + v.y * w.y; }

// usecase: Compute 2D cross product (determinant) of vectors v and w.
// returns: v.x * w.y - v.y * w.x (>0 CCW, <0 CW, =0 collinear).
T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; }

// usecase: Check orientation of point c relative to directed line ab.
// returns: >0 for CCW turn, <0 for CW turn, 0 if collinear.
T orient(pt a, pt b, pt c) { return cross(b - a, c - a); }

// usecase: Rotate vector p by 90 degrees counter-clockwise.
// returns: Perpendicular vector {-p.y, p.x}.
pt perp(pt p) { return {-p.y, p.x}; }

// usecase: Check if two vectors v and w are strictly perpendicular.
// returns: true if dot product is 0 (within EPS).
bool isPerp(pt v, pt w) { return abs(dot(v, w)) < EPS; }

// usecase: Check if two vectors v and w are parallel or collinear.
// returns: true if cross product is 0 (within EPS).
bool isParallel(pt v, pt w) { return abs(cross(v, w)) < EPS; }

/** * POINT UTILS 
 */
struct PointUtils {
    // usecase: Comparator to sort points radially around origin via angles.
    // returns: true if polar angle of a is strictly less than b.
    static bool angleCompare(pt a, pt b) {
        return atan2(a.y, a.x) < atan2(b.y, b.x);
    }

    // usecase: Rotate standard 2D coordinates around origin by theta radians.
    // returns: void (modifies xx and yy in-place).
    static void rotatePoint(double &xx, double &yy, double theta) {
        double nx = xx * cos(theta) - yy * sin(theta);
        double ny = xx * sin(theta) + yy * cos(theta);
        xx = nx;
        yy = ny;
    }
};

/** * TRANSFORMATIONS 
 */
struct Transform {
    // usecase: Shift point p by direction vector v.
    // returns: Translated point p + v.
    static pt translate(pt p, pt v) { return p + v; }

    // usecase: Scale point p away from center by factor.
    // returns: Scaled point coordinates.
    static pt scale(pt p, pt center, T factor) { return center + (p - center) * factor; }

    // usecase: Rotate point p around center by angle a (in radians).
    // returns: Rotated point coordinates.
    static pt rotate(pt p, pt center, T a) { 
        return center + (p - center) * pt(cos(a), sin(a)); 
    }

    // usecase: Map point p from segment [a, b] to segment [fa, fb].
    // returns: Linearly interpolated point on target segment.
    static pt linearTransform(pt p, pt a, pt fa, pt b, pt fb) {
        return fa + (p - a) * (fb - fa) / (b - a);
    }
};

/** * ANGLES 
 */
struct AngleUtils {
    // usecase: Find smallest angle between vectors v and w.
    // returns: Angle in radians within range [0, PI].
    static T angle(pt v, pt w) {
        if (abs(v) < EPS || abs(w) < EPS) return 0;
        return acos(clamp(dot(v, w) / (abs(v) * abs(w)), (T)-1.0, (T)1.0));
    }   

    // usecase: Find directed angle from vector ab to ac.
    // returns: Angle in radians within full circle range [0, 2*PI).
    static T orientedAngle(pt a, pt b, pt c) {
        T ang = angle(b - a, c - a);
        return (orient(a, b, c) >= 0) ? ang : 2 * PI - ang;
    } 

    // usecase: Find signed angle traveled turning from ab to ac.
    // returns: Signed angle in radians within range (-PI, PI].
    static T angleTraveled(pt a, pt b, pt c) {
        T ang = angle(b - a, c - a);
        return (orient(a, b, c) >= 0) ? ang : -ang;
    }

    // usecase: Check if point p lies inside angle cone formed by bac (inclusive).
    // returns: true if p is inside or on boundary of angle bac.
    static bool inAngle(pt a, pt b, pt c, pt p) {
        T abp = orient(a, b, p);
        T acp = orient(a, c, p);
        T abc = orient(a, b, c);
        if (abs(abc) < EPS) return sgn(dot(b - a, p - a)) >= 0 && sgn(dot(c - a, p - a)) >= 0;
        if (abc < 0) swap(abp, acp);
        return (abp >= -EPS && acp <= EPS) ^ (abc < -EPS);
    }
};

/** * LINES 
 */
struct line {
    pt v; T c; 

    // usecase: Construct line from direction vector v and offset c.
    // returns: Initialized line object where dot(perp(v), p) = c.
    line(pt v, T c) : v(v), c(c) {}

    // usecase: Construct line from standard algebra equation ax + by = _c.
    // returns: Initialized line object.
    line(T a, T b, T _c) : v({b, -a}), c(_c) {}

    // usecase: Construct directed line passing through points p and q.
    // returns: Initialized line object directed from p to q.
    line(pt p, pt q) : v(q - p), c(cross(v, p)) {}

    // usecase: Extract standard linear algebra coefficients (A, B, C) for Ax + By + C = 0.
    // returns: Tuple of coefficients {A, B, C}.
    tuple<T,T,T> getEquation() const {
        return {-v.y, v.x, -c};
    }

    // usecase: Evaluate side of line point p lies on.
    // returns: CW > 0, CCW < 0, exactly on line = 0.
    T side(pt p) const { return cross(v, p) - c; }

    // usecase: Compute shortest Euclidean distance from point p to line.
    // returns: Perpendicular distance value.
    T dist(pt p) const { return abs(side(p)) / abs(v); }

    // usecase: Compute squared shortest distance from p to line (avoids sqrt).
    // returns: Squared perpendicular distance.
    T sqDist(pt p) const { return (side(p) * side(p)) / sq(v); }
    
    // usecase: Construct a new line perpendicular to current line passing through p.
    // returns: Perpendicular line object.
    line perpThrough(pt p) const { return {perp(v), cross(perp(v), p)}; }

    // usecase: Find orthogonal projection of point p onto line.
    // returns: Projected point coordinates on the line.
    pt proj(pt p) const { return p - perp(v) * side(p) / sq(v); }

    // usecase: Reflect point p across the line like a mirror.
    // returns: Reflected point coordinates.
    pt refl(pt p) const { return p - perp(v) * (T)2.0 * side(p) / sq(v); }

    // usecase: Translate line by direction vector t.
    // returns: New translated line object.
    line translate(pt t) const { return {v, c + cross(v, t)}; }

    // usecase: Shift line parallel to itself to the left by perpendicular distance dist.
    // returns: New shifted line object.
    line shiftLeft(T dist) const { return {v, c + dist * abs(v)}; }

    // usecase: Find intersection point of lines l1 and l2.
    // returns: true if unique intersection exists (stored in out), false if parallel.
    static bool inter(line l1, line l2, pt &out) {
        T d = cross(l1.v, l2.v);
        if (abs(d) < EPS) return false;
        out = (l2.v * l1.c - l1.v * l2.c) / d; 
        return true;
    }

    // usecase: Construct angle bisector line between l1 and l2.
    // returns: Interior bisector if interior=true, exterior bisector otherwise.
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

    // usecase: Compare relative order of projections of two points onto the line direction.
    // returns: true if projection of p comes strictly before q along vector v.
    bool cmpProj(pt p, pt q) const {
        return dot(v, p) < dot(v, q);
    }
    
    // usecase: Comparator to sort lines by angle, then by distance from origin.
    // returns: true if current line is smaller than l.
    bool operator < (const line& l) const {
        auto ang = [](pt p) { return atan2(p.y, p.x); };
        T a1 = ang(v), a2 = ang(l.v);
        if (abs(a1 - a2) > EPS) return a1 < a2;
        return c < l.c;
    }
};

/** * COMPLETE 2D TRIANGLE TEMPLATE
 */
struct Triangle {
    pt A, B, C;
    T a, b, c; // a opposite A, b opposite B, c opposite C

    // usecase: Construct triangle from vertices and auto-calculate side lengths.
    // returns: Initialized Triangle object.
    Triangle(pt A, pt B, pt C) : A(A), B(B), C(C) {
        a = abs(C - B);
        b = abs(C - A);
        c = abs(B - A);
    }

    // usecase: Validate if three side lengths satisfy triangle inequality.
    // returns: true if sides can form a valid non-degenerate triangle.
    static bool isValidSides(T sa, T sb, T sc) {
        return (sa + sb > sc + EPS) && (sa + sc > sb + EPS) && (sb + sc > sa + EPS);
    }

    // usecase: Check if triangle vertices are non-collinear.
    // returns: true if area is non-zero.
    bool isValid() const {
        return abs(orient(A, B, C)) > EPS;
    }

    // usecase: Calculate interior angle at vertex A.
    // returns: Angle A in radians using Law of Cosines.
    T angleA() const {
        return acos(clamp((b * b + c * c - a * a) / (2 * b * c), (T)-1.0, (T)1.0));
    }

    // usecase: Calculate interior angle at vertex B.
    // returns: Angle B in radians using Law of Cosines.
    T angleB() const {
        return acos(clamp((a * a + c * c - b * b) / (2 * a * c), (T)-1.0, (T)1.0));
    }

    // usecase: Calculate interior angle at vertex C.
    // returns: Angle C in radians using Law of Cosines.
    T angleC() const {
        return acos(clamp((a * a + b * b - c * c) / (2 * a * b), (T)-1.0, (T)1.0));
    }

    // usecase: Compute perimeter sum of all sides.
    // returns: a + b + c.
    T perimeter() const { return a + b + c; }

    // usecase: Compute semi-perimeter value s.
    // returns: perimeter / 2.
    T semiPerimeter() const { return perimeter() / (T)2.0; }

    // usecase: Compute signed area (positive CCW, negative CW).
    // returns: Half of cross product determinant.
    T signedArea() const { return orient(A, B, C) / (T)2.0; }

    // usecase: Compute positive Euclidean area.
    // returns: Absolute value of signed area.
    T area() const { return abs(signedArea()); }

    // usecase: Calculate area purely from three side lengths.
    // returns: Area via Heron's formula.
    static T areaHeron(T sa, T sb, T sc) {
        T s = (sa + sb + sc) / (T)2.0;
        T val = s * (s - sa) * (s - sb) * (s - sc);
        return sqrt(max((T)0.0, val));
    }

    // usecase: Calculate area from two sides and their included angle.
    // returns: 0.5 * side1 * side2 * sin(theta).
    static T areaTwoSidesAngle(T side1, T side2, T theta) {
        return (T)0.5 * side1 * side2 * sin(theta);
    }

    // usecase: Calculate area using one side and three interior angles.
    // returns: Area via Law of Sines derivation.
    static T areaSideAngles(T sa, T angA, T angB) {
        T angC = PI - angA - angB;
        return (sa * sa * sin(angB) * sin(angC)) / ((T)2.0 * sin(angA));
    }

    // usecase: Calculate area using circumradius R and three angles.
    // returns: 2 * R^2 * sin(A) * sin(B) * sin(C).
    static T areaRadiusAngles(T R, T angA, T angB, T angC) {
        return (T)2.0 * R * R * sin(angA) * sin(angB) * sin(angC);
    }

    // usecase: Compute altitude height from vertex A to side BC.
    // returns: 2 * Area / a.
    T altitudeA() const { return ((T)2.0 * area()) / a; }

    // usecase: Compute altitude height from vertex B to side AC.
    // returns: 2 * Area / b.
    T altitudeB() const { return ((T)2.0 * area()) / b; }

    // usecase: Compute altitude height from vertex C to side AB.
    // returns: 2 * Area / c.
    T altitudeC() const { return ((T)2.0 * area()) / c; }

    // usecase: Compute median length from vertex A to midpoint of BC.
    // returns: Median length via Apollonius's theorem.
    T medianA() const { return (T)0.5 * sqrt(max((T)0.0, (T)2.0 * b * b + (T)2.0 * c * c - a * a)); }

    // usecase: Compute median length from vertex B to midpoint of AC.
    // returns: Median length via Apollonius's theorem.
    T medianB() const { return (T)0.5 * sqrt(max((T)0.0, (T)2.0 * a * a + (T)2.0 * c * c - b * b)); }

    // usecase: Compute median length from vertex C to midpoint of AB.
    // returns: Median length via Apollonius's theorem.
    T medianC() const { return (T)0.5 * sqrt(max((T)0.0, (T)2.0 * a * a + (T)2.0 * b * b - c * c)); }

    // usecase: Find Centroid (intersection of medians, center of mass).
    // returns: Average point of vertices (A + B + C) / 3.
    pt centroid() const { return (A + B + C) / (T)3.0; }

    // usecase: Find Incenter (center of inscribed circle).
    // returns: Weighted vertex average by opposite side lengths.
    pt incenter() const { return (A * a + B * b + C * c) / perimeter(); }

    // usecase: Find Circumcenter (center of circumscribed circle).
    // returns: Intersection of perpendicular bisectors of sides.
    pt circumcenter() const {
        pt v1 = B - A, v2 = C - A;
        T d = (T)2.0 * cross(v1, v2);
        if (abs(d) < EPS) return A;
        pt num = v2 * sq(v1) - v1 * sq(v2);
        return A + pt(num.y, -num.x) / d;
    }

    // usecase: Find Orthocenter (intersection of altitudes).
    // returns: Point H derived via Euler line relation.
    pt orthocenter() const { return A + B + C - (T)2.0 * circumcenter(); }

    // usecase: Compute radius of incircle.
    // returns: Area / semiPerimeter.
    T inradius() const { return area() / semiPerimeter(); }

    // usecase: Compute radius of circumcircle.
    // returns: (a * b * c) / (4 * Area).
    T circumradius() const { return (a * b * c) / ((T)4.0 * area()); }

    // usecase: Check if point P lies inside triangle bounds.
    // returns: true if P is inside (strict=true excludes edge boundary).
    bool contains(pt P, bool strict = false) const {
        T o1 = orient(A, B, P), o2 = orient(B, C, P), o3 = orient(C, A, P);
        if (strict) return (o1 > EPS && o2 > EPS && o3 > EPS) || (o1 < -EPS && o2 < -EPS && o3 < -EPS);
        return (o1 >= -EPS && o2 >= -EPS && o3 >= -EPS) || (o1 <= EPS && o2 <= EPS && o3 <= EPS);
    }

    // usecase: Classify triangle by angle types.
    // returns: 0 Right-angled, 1 Acute, -1 Obtuse.
    int angleClassification() const {
        vector<T> s = {a, b, c};
        sort(s.begin(), s.end());
        T diff = s[0] * s[0] + s[1] * s[1] - s[2] * s[2];
        return abs(diff) < EPS ? 0 : (diff > 0 ? 1 : -1);
    }

    // usecase: Classify triangle by side equality.
    // returns: 3 Equilateral, 2 Isosceles, 1 Scalene.
    int sideClassification() const {
        bool ab = abs(a - b) < EPS, bc = abs(b - c) < EPS, ac = abs(a - c) < EPS;
        if (ab && bc) return 3;
        if (ab || bc || ac) return 2;
        return 1;
    }
};

/** * SEGMENTS 
 */
struct SegmentUtils {
    // usecase: Check if point p lies inside disk with diameter ab.
    // returns: true if dot product of vectors to p is <= 0.
    static bool inDisk(pt a, pt b, pt p) {
        return dot(a - p, b - p) <= EPS;
    }

    // usecase: Check if point p lies strictly on line segment [a, b].
    // returns: true if collinear and inside bounding disk.
    static bool onSegment(pt a, pt b, pt p) {
        return sgn(orient(a, b, p)) == 0 && inDisk(a, b, p);
    }

    // usecase: Check if segments [a,b] and [c,d] intersect properly at single interior point.
    // returns: true if segments straddle each other (intersection stored in out).
    static bool properInter(pt a, pt b, pt c, pt d, pt &out) {
        T oa = orient(c, d, a), ob = orient(c, d, b);
        T oc = orient(a, b, c), od = orient(a, b, d);
        if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0) {
            out = (a * ob - b * oa) / (ob - oa);
            return true;
        }
        return false;
    }

    struct pt_cmp {
        bool operator()(const pt& a, const pt& b) const {
            if (abs(a.x - b.x) > EPS) return a.x < b.x;
            if (abs(a.y - b.y) > EPS) return a.y < b.y;
            return false;
        }
    };

    // usecase: Find all intersection points between segments [a,b] and [c,d].
    // returns: Vector of unique intersection points (size 0, 1, or 2).
    static vector<pt> segmentInter(pt a, pt b, pt c, pt d) {
        pt out;
        if (properInter(a, b, c, d, out)) return {out};
        vector<pt> res;
        if (onSegment(a, b, c)) res.push_back(c);
        if (onSegment(a, b, d)) res.push_back(d);
        if (onSegment(c, d, a)) res.push_back(a);
        if (onSegment(c, d, b)) res.push_back(b);
        sort(res.begin(), res.end(), [](pt p1, pt p2) {
            return abs(p1.x - p2.x) > EPS ? p1.x < p2.x : p1.y < p2.y;
        });
        res.erase(unique(res.begin(), res.end(), [](pt p1, pt p2) {
            return abs(p1 - p2) < EPS;
        }), res.end());
        return res;
    }

    // usecase: Compute shortest Euclidean distance from point p to segment [a, b].
    // returns: Distance to segment boundary or perpendicular projection.
    static T distToSeg(pt a, pt b, pt p) {
        if (a == b) return abs(p - a);
        T proj_val = dot(p - a, b - a);
        if (proj_val <= 0) return abs(p - a);
        if (proj_val >= sq(b - a)) return abs(p - b);
        return abs(cross(p - a, b - a)) / abs(b - a);
    }

    // usecase: Compute shortest distance between two segments [a,b] and [c,d].
    // returns: 0 if intersecting, otherwise min distance between endpoints/projections.
    static T segTosegDist(pt a, pt b, pt c, pt d) {
        pt out;
        if (properInter(a, b, c, d, out)) return 0;
        return min({distToSeg(a, b, c), distToSeg(a, b, d),
                    distToSeg(c, d, a), distToSeg(c, d, b)});
    }
};

/** * RAY 
 */
struct ray {
    pt o, d; 

    // usecase: Construct ray from origin point o and direction vector d.
    // returns: Initialized ray object.
    ray(pt o, pt d) : o(o), d(d) {}

    // usecase: Construct ray starting at point a directed toward point b.
    // returns: Initialized ray object with direction b - a.
    static ray fromPoints(pt a, pt b) {
        return ray(a, b - a);
    }

    // usecase: Get coordinates of point at distance/parameter t along ray.
    // returns: Point o + d * t.
    pt at(T t) const { return o + d * t; }

    // usecase: Check if point p lies strictly on the ray forward trajectory.
    // returns: true if collinear and forward directed (t >= 0).
    bool onRay(pt p) const {
        if (abs(p - o) < EPS) return true;
        return sgn(cross(d, p - o)) == 0 && sgn(dot(d, p - o)) >= 0;
    }

    // usecase: Compute shortest distance from point p to the ray.
    // returns: Distance to origin if behind ray, perpendicular distance otherwise.
    T dist(pt p) const {
        if (sgn(dot(d, p - o)) <= 0) return abs(p - o); 
        return abs(cross(d, p - o)) / abs(d);
    }

    // usecase: Compute shortest distance between this ray and another ray r.
    // returns: 0 if intersecting, otherwise minimum distance to origins/trajectories.
    T dist(const ray& r) const {
        pt out;
        if (intersect(r, out)) return 0;
        return min(dist(r.o), r.dist(o));
    }

    // usecase: Find orthogonal projection of point p onto ray trajectory.
    // returns: Projected point (clamped to origin if projection falls behind).
    pt proj(pt p) const {
        T t = dot(p - o, d) / sq(d);
        if (t <= 0) return o; 
        return o + d * t;
    }

    // usecase: Check if ray directions are parallel or anti-parallel.
    // returns: true if cross product of direction vectors is 0.
    bool isParallel(const ray& r) const {
        return abs(cross(d, r.d)) < EPS;
    }

    // usecase: Check if both rays lie on the exact same infinite line.
    // returns: true if parallel and origins align.
    bool isCollinear(const ray& r) const {
        return isParallel(r) && abs(cross(d, r.o - o)) < EPS;
    }

    // usecase: Find single intersection point between this ray and ray r.
    // returns: true if unique intersection exists (t1 >= 0 and t2 >= 0), stored in out.
    bool intersect(const ray& r, pt &out) const {
        T den = cross(d, r.d);
        if (abs(den) < EPS) return false; 
        T t1 = cross(r.o - o, r.d) / den;
        T t2 = cross(r.o - o, d) / den;
        if (t1 >= -EPS && t2 >= -EPS) {
            out = at(t1);
            return true;
        }
        return false;
    }

    // usecase: Find intersection between ray and finite segment [a, b].
    // returns: true if intersection hits within segment bounds (stored in out).
    bool intersectSeg(pt a, pt b, pt &out) const {
        pt seg_d = b - a;
        T den = cross(d, seg_d);
        if (abs(den) < EPS) return false; 
        T t_ray = cross(a - o, seg_d) / den;
        T t_seg = cross(a - o, d) / den;
        if (t_ray >= -EPS && t_seg >= -EPS && t_seg <= 1.0 + EPS) {
            out = at(t_ray);
            return true;
        }
        return false;
    }
};

/** * POLYGONS 
 */
struct PolygonUtils {
    // usecase: Compute area of polygon given in sequential boundary order.
    // returns: Absolute area using shoelace cross product formula.
    static T areaRegular(int n, T side) {
        return (T)n * side * side / (T)4.0 / tan(PI / (T)n);
    } 
    
    static T areaPolygon(const vector<pt>& p) {
        T area = 0;
        int n = p.size();
        for (int i = 0; i < n; i++) {
            area += cross(p[i], p[(i + 1) % n]);
        }
        return abs(area) / 2.0;
    }

    // usecase: Compute area of unordered set of points forming a convex polygon.
    // returns: Area after sorting vertices radially around center of mass.
    static T areaPolygon2(vector<pt> p) {
        int n = p.size();
        if (n < 3) return 0;
        pt center(0, 0);
        for (const auto &v : p) center += v;
        center /= (T)n;
        sort(p.begin(), p.end(), [&](pt a, pt b) {
            return atan2(a.y - center.y, a.x - center.x) <
                   atan2(b.y - center.y, b.x - center.x);
        });
        T area = 0;
        for (int i = 0; i < n; i++)
            area += cross(p[i], p[(i + 1) % n]);
        return abs(area) / 2.0;
    }

    // usecase: Check if point a lies inside simple polygon p via ray casting.
    // returns: true if inside (strict=true excludes boundary edges).
    static bool inPolygon(const vector<pt>& p, pt a, bool strict = true) {
        int cnt = 0;
        for (int i = 0, n = p.size(); i < n; i++) {
            pt q = p[i], r = p[(i + 1) % n];
            if (SegmentUtils::onSegment(q, r, a)) return !strict;
            bool up = (q.y <= a.y && a.y < r.y);
            bool down = (r.y <= a.y && a.y < q.y);
            if (up || down) {
                if (orient(q, r, a) > 0 == (q.y < r.y)) {
                    cnt++;
                }
            }
        }
        return cnt & 1;
    }

    static T convexDiameter(const vector<pt>& p) {
        int n = p.size();
        if (n < 2) return 0;
        if (n == 2) return abs(p[0] - p[1]);
        int k = 1;
        while (abs(cross(p[(k + 1) % n] - p[0], p[1] - p[0])) > abs(cross(p[k] - p[0], p[1] - p[0]))) {
            k = (k + 1) % n;
        }
        T res = 0;
        for (int i = 0, j = k; i <= k && j < n; i++) {
            res = max(res, abs(p[i] - p[j]));
            while (j < n && abs(cross(p[(j + 1) % n] - p[i], p[(i + 1) % n] - p[i])) > abs(cross(p[j] - p[i], p[(i + 1) % n] - p[i]))) {
                res = max(res, abs(p[i] - p[(j + 1) % n]));
                j = (j + 1) % n;
            }
        }
        return res;
    }
};

/** * CIRCLES 
 */
struct circle {
    pt c; T r;

    // usecase: Default constructor creating circle at origin with radius 0.
    // returns: Initialized circle object.
    circle() : c(0,0), r(0) {}

    // usecase: Construct circle centered at point c with radius r.
    // returns: Initialized circle object.
    circle(pt c, T r) : c(c), r(r) {}

    // usecase: Find intersection points between circle and infinite line l.
    // returns: Vector of 0, 1, or 2 intersection points.
    vector<pt> intersect(line l) const {
        pt proj = l.proj(c);
        T dist_sq = sq(proj - c);
        if (dist_sq > r * r + EPS) return {};
        if (abs(dist_sq - r * r) < EPS) return {proj};
        T offset = sqrt(max((T)0, r * r - dist_sq));
        pt dir = l.v / abs(l.v);
        return {proj + dir * offset, proj - dir * offset};
    }

    // usecase: Find intersection points between this circle and circle o.
    // returns: Vector of 0, 1, or 2 intersection points.
    vector<pt> intersect(const circle& o) const {
        T d2 = sq(c - o.c), d = sqrt(d2);
        if (d > r + o.r + EPS || d < abs(r - o.r) - EPS || d < 1e-12) return {};
        T a = (r * r - o.r * o.r + d2) / (2 * d);
        T h = sqrt(max((T)0, r * r - a * a));
        pt p2 = c + a * (o.c - c) / d;
        pt vec = (o.c - c) * pt(0, h / d);
        return {p2 + vec, p2 - vec};
    }

    // usecase: Find all unique intersection points among a collection of circles.
    // returns: Vector of points lying on boundaries of intersecting circles without being outside others.
    static vector<pt> intersect(const vector<circle>& circles) {
        vector<pt> res;
        for (size_t i = 0; i < circles.size(); i++) {
            for (size_t j = i + 1; j < circles.size(); j++) {
                for (pt p : circles[i].intersect(circles[j])) {
                    bool ok = true;
                    for (const auto& c : circles) {
                        if (abs(p - c.c) > c.r + EPS) { ok = false; break; }
                    }
                    if (ok) {
                        bool dup = false;
                        for (pt op : res) if (abs(p - op) < EPS) dup = true;
                        if (!dup) res.push_back(p);
                    }
                }
            }
        }
        return res;
    }

    // usecase: Compute overlapping area between two circles.
    // returns: Area of lens intersection region.
    T intersection_area(circle other) const {
        T d = abs(other.c - c);
        if (d >= r + other.r - EPS) return 0;
        if (d <= abs(r - other.r) + EPS) return PI * min(r, other.r) * min(r, other.r);
        
        T a1 = acos(clamp((r * r + d * d - other.r * other.r) / (2 * r * d), (T)-1.0, (T)1.0));
        T a2 = acos(clamp((other.r * other.r + d * d - r * r) / (2 * other.r * d), (T)-1.0, (T)1.0));
        return r * r * a1 + other.r * other.r * a2 - r * d * sin(a1);
    }

    // usecase: Calculate area of circle sector given central angle in radians.
    // returns: Sector area 0.5 * r^2 * theta.
    T sector_area_rad(T theta) const {
        return 0.5 * r * r * theta;
    }

    // usecase: Calculate area of circle sector given central angle in degrees.
    // returns: Sector area from degree conversion.
    T sector_area_deg(T theta) const {
        return (theta / 360.0) * PI * r * r;
    }

    // usecase: Find tangent points on circle boundary from external point p.
    // returns: Vector of 0, 1 (if on circle), or 2 tangent touch points.
    vector<pt> tangent_points(pt p) const {
        T d = abs(p - c);
        if (d < r - EPS) return {};
        if (abs(d - r) < EPS) return {p};
        T a = acos(clamp(r / d, (T)-1.0, (T)1.0)), b = arg(p - c);
        return {c + polar(r, b + a), c + polar(r, b - a)};
    }

    // usecase: Find all tangent lines connecting this circle to circle other.
    // returns: Vector of internal (inner=true) or external tangent lines.
    vector<line> tangents(circle other, bool inner) const {
        vector<line> res;
        pt d = other.c - c;
        T dr = inner ? r + other.r : r - other.r;
        T dist = abs(d);
        if (dist < EPS && abs(r - other.r) < EPS) return res;
        if (dist < abs(dr) - EPS) return res;
        if (abs(dist - abs(dr)) < EPS) {
            pt p = c + d * (dr > 0 ? r : -r) / dist;
            res.push_back(line(p, p + perp(d)));
            return res;
        }

        T a = acos(clamp(dr / dist, (T)-1.0, (T)1.0));
        T b = arg(d);
        T offset = inner ? PI : 0;
        
        res.push_back(line(c + polar(r, b + a), other.c + polar(other.r, b + a + offset)));
        res.push_back(line(c + polar(r, b - a), other.c + polar(other.r, b - a + offset)));
        return res;
    }
};

/** * ADVANCED HULL & SUM TECHNIQUES 
 */
struct HullUtils {
    // usecase: Compute 2D Convex Hull using Monotone Chain algorithm.
    // returns: void (modifies pts in-place to CCW hull boundary points).
    static void convex_hull(vector<pt> &pts, bool collinear_inc = true) {
        if (pts.size() <= 1) return;
        sort(pts.begin(), pts.end(), [](const pt& a, const pt& b) {
            if (fabs(a.x - b.x) > EPS) return a.x < b.x;
            return a.y < b.y;
        });
        vector<pt> hull;
        auto bad = [&](const pt& a, const pt& b, const pt& c) {
            double o = orient(a, b, c);
            return collinear_inc ? o < -EPS : o <= EPS;
        };

        for (const pt& p : pts) {
            while (hull.size() >= 2 && bad(hull[hull.size() - 2], hull.back(), p)) {
                hull.pop_back();
            }
            hull.push_back(p);
        }

        int t = hull.size() + 1;
        for (int i = (int)pts.size() - 2; i >= 0; --i) {
            while ((int)hull.size() >= t && bad(hull[hull.size() - 2], hull.back(), pts[i])) {
                hull.pop_back();
            }
            hull.push_back(pts[i]);
        }

        hull.pop_back();
        pts = hull;
    }

    // usecase: Check if polygon vertices are ordered counter-clockwise.
    // returns: true if total shoelace area is strictly positive.
    static bool isCCW(const vector<pt>& p) {
        int n = p.size();
        T area = 0;
        for (int i = 0; i < n; i++) area += cross(p[i], p[(i + 1) % n]);
        return area > EPS;
    }

    // usecase: Align polygon starting from bottom-leftmost vertex for Minkowski algorithms.
    // returns: void (rotate-shifts vector in-place).
    static void reorder(vector<pt>& p) {
        int pos = 0;
        for (int i = 1; i < (int)p.size(); i++) {
            if (p[i].y < p[pos].y - EPS || (abs(p[i].y - p[pos].y) <= EPS && p[i].x < p[pos].x - EPS)) {
                pos = i;
            }
        }
        rotate(p.begin(), p.begin() + pos, p.end());
    }

    // usecase: Compute Minkowski sum of two convex polygons a and b in linear time.
    // returns: Vector of vertices representing the combined Minkowski polygon boundary.
    static vector<pt> minkowskiSum(vector<pt> a, vector<pt> b) {
        if (a.empty() || b.empty()) return {};
        reorder(a); reorder(b);
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        vector<pt> res;
        
        while (i < n || j < m) {
            res.push_back(a[i % n] + b[j % m]);
            pt edgeA = a[(i + 1) % n] - a[i % n];
            pt edgeB = b[(j + 1) % m] - b[j % m];
            if (i < n && j < m) {
                T cross_prod = cross(edgeA, edgeB);
                if (abs(cross_prod) <= EPS && dot(edgeA, edgeB) > 0) {
                    i++; j++;
                } else if (cross_prod > EPS) {
                    i++; 
                } else {
                    j++; 
                }
            } else if (i < n) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};

struct RegularPyramid {
    int n;       // Number of base sides
    double a;    // Base side length
    double h;    // Height

    double base_area() const {
        return (n * a * a) / (4.0 * tan(PI / n));
    }

    double volume() const {
        return (1.0 / 3.0) * base_area() * h;
    }

    double circumradius() const {
        return a / (2.0 * sin(PI / n));
    }

    double inradius() const {
        return a / (2.0 * tan(PI / n));
    }

    double lateral_edge() const {
        double R = circumradius();
        return sqrt(h * h + R * R);
    }

    double slant_height() const {
        double r = inradius();
        return sqrt(h * h + r * r);
    }

    double lateral_area() const {
        return 0.5 * n * a * slant_height();
    }

    double total_surface_area() const {
        return base_area() + lateral_area();
    }

    // Factory method: build pyramid when all edges (base + lateral) are equal
    static RegularPyramid from_equal_edges(int n, double l) {
        double R = l / (2.0 * sin(PI / n));
        double h = sqrt(l * l - R * R);
        return {n, l, h};
    }
};


/** * ADVANCED POLYGON & HALF-PLANE ALGORITHMS 
 */
struct AdvancedPolygonUtils {
    // usecase: Check if point a lies inside a CCW convex polygon in logarithmic time.
    // returns: true if point is strictly inside (strict=true excludes edge boundary).
    static bool inConvexPolygonLogN(const vector<pt>& p, pt a, bool strict = true) {
        int n = p.size();
        if (n < 3) return false;
        if (orient(p[0], p[1], a) < (strict ? EPS : -EPS)) return false;
        if (orient(p[0], p[n - 1], a) > (strict ? -EPS : EPS)) return false;
        
        int l = 1, r = n - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (orient(p[0], p[mid], a) >= 0) l = mid;
            else r = mid;
        }
        return orient(p[l], p[r], a) >= (strict ? EPS : -EPS);
    }

    // usecase: Cut a polygon by directed line (a, b) keeping only the left side (CCW).
    // returns: Vector of vertices representing the clipped polygon boundary.
    static vector<pt> cutPolygon(const vector<pt>& p, pt a, pt b) {
        vector<pt> res;
        line l(a, b);
        for (int i = 0, n = p.size(); i < n; i++) {
            pt cur = p[i], nxt = p[(i + 1) % n];
            if (orient(a, b, cur) >= -EPS) res.push_back(cur);
            if (sgn(orient(a, b, cur)) * sgn(orient(a, b, nxt)) < 0) {
                pt out;
                line::inter(l, line(cur, nxt), out);
                res.push_back(out);
            }
        }
        return res;
    }

    // usecase: Find extreme tangent points on a CCW convex polygon from an external point a in O(log N).
    // returns: Pair of vertex indices {rightmost_tangent, leftmost_tangent} relative to view from point a.
    static pair<int, int> tangentsFromExternalPoint(const vector<pt>& p, pt a) {
        int n = p.size();
        auto isLeft = [&](int i, pt pt_val) {
            return orient(a, p[i], pt_val) > EPS;
        };
        
        int r_idx = 0, l_idx = 0;
        for (int i = 1; i < n; i++) {
            if (orient(a, p[r_idx], p[i]) < -EPS) r_idx = i;
            if (orient(a, p[l_idx], p[i]) > EPS) l_idx = i;
        }
        return {r_idx, l_idx};
    }

    // usecase: Compute the intersection of multiple directed half-planes (left side of each line) in O(N log N).
    // returns: Vector of CCW vertices forming the bounding polygon of the intersection (empty if infeasible).
    static vector<pt> halfPlaneIntersection(vector<line> H) {
        pt box_min(-1e9, -1e9), box_max(1e9, 1e9);
        H.push_back(line({box_min.x, box_min.y}, {box_max.x, box_min.y}));
        H.push_back(line({box_max.x, box_min.y}, {box_max.x, box_max.y}));
        H.push_back(line({box_max.x, box_max.y}, {box_min.x, box_max.y}));
        H.push_back(line({box_min.x, box_max.y}, {box_min.x, box_min.y}));

        sort(H.begin(), H.end());
        deque<line> q;
        deque<pt> ans;

        for (int i = 0; i < (int)H.size(); i++) {
            while (ans.size() > 0 && H[i].side(ans.back()) < -EPS) {
                ans.pop_back();
                q.pop_back();
            }
            while (ans.size() > 0 && H[i].side(ans.front()) < -EPS) {
                ans.pop_front();
                q.pop_front();
            }
            if (q.size() > 0 && abs(cross(q.back().v, H[i].v)) < EPS) {
                if (dot(q.back().v, H[i].v) > 0) {
                    if (H[i].c < q.back().c) q.back() = H[i];
                    continue;
                }
                return {};
            }
            q.push_back(H[i]);
            if (q.size() > 1) {
                pt p;
                line::inter(q.back(), q[q.size() - 2], p);
                ans.push_back(p);
            }
        }
        while (ans.size() > 0 && q.front().side(ans.back()) < -EPS) {
            ans.pop_back();
            q.pop_back();
        }
        if (q.size() <= 2) return {};
        pt p;
        line::inter(q.front(), q.back(), p);
        ans.push_back(p);
        return vector<pt>(ans.begin(), ans.end());
    }
};


