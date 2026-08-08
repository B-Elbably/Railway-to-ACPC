#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
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


void solve() {
    int n, r;
    cin >> n >> r;
    T ang1 = PI / n;
    T ang2 = ang1 / 2.0;
    T area = Triangle::areaSideAngles(r, PI - ang2 - ang1, ang2);
    cout << fixed << setprecision(10) << area * n * 2 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
