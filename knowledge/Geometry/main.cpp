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

int sgn(T val) { return (val > EPS) - (val < -EPS); }
T sq(pt p) { return p.x * p.x + p.y * p.y; }
T dot(pt v, pt w) { return v.x * w.x + v.y * w.y; }
T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; }
T orient(pt a, pt b, pt c) { return cross(b - a, c - a); }

pt perp(pt p) { return {-p.y, p.x}; }
bool isPerp(pt v, pt w) { return abs(dot(v, w)) < EPS; }
bool isParallel(pt v, pt w) { return abs(cross(v, w)) < EPS; }

bool angleCompare(pt a, pt b) {
    return atan2(a.y, a.x) < atan2(b.y, b.x);
}

void rotatePoint(double &xx, double &yy, double theta) {
    double nx = xx * cos(theta) - yy * sin(theta);
    double ny = xx * sin(theta) + yy * cos(theta);
    xx = nx;
    yy = ny;
}

/** * TRANSFORMATIONS 
 */
pt translate(pt p, pt v) { return p + v; }
pt scale(pt p, pt center, T factor) { return center + (p - center) * factor; }
pt rotate(pt p, pt center, T a) { 
    return center + (p - center) * pt(cos(a), sin(a)); 
}

pt linearTransform(pt p, pt a, pt fa, pt b, pt fb) {
    return fa + (p - a) * (fb - fa) / (b - a);
}

/** * ANGLES 
 */
T angle(pt v, pt w) {
    if (abs(v) < EPS || abs(w) < EPS) return 0;
    return acos(clamp(dot(v, w) / (abs(v) * abs(w)), (T)-1.0, (T)1.0));
}   

T orientedAngle(pt a, pt b, pt c) {
    T ang = angle(b - a, c - a);
    return (orient(a, b, c) >= 0) ? ang : 2 * PI - ang;
} 

T angleTraveled(pt a, pt b, pt c) {
    T ang = angle(b - a, c - a);
    return (orient(a, b, c) >= 0) ? ang : -ang;
}

bool inAngle(pt a, pt b, pt c, pt p) {
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
    line(pt v, T c) : v(v), c(c) {}
    line(T a, T b, T _c) : v({b, -a}), c(_c) {}
    line(pt p, pt q) : v(q - p), c(cross(v, p)) {}

    tuple<T,T,T> getEquation() const {
        return {-v.y, v.x, -c};
    }

    T side(pt p) { return cross(v, p) - c; }
    T dist(pt p) { return abs(side(p)) / abs(v); }
    T sqDist(pt p) { return (side(p) * side(p)) / sq(v); }
    
    line perpThrough(pt p) { return {perp(v), cross(perp(v), p)}; }
    pt proj(pt p) { return p - perp(v) * side(p) / sq(v); }
    pt refl(pt p) { return p - perp(v) * (T)2.0 * side(p) / sq(v); }

    line translate(pt t) { return {v, c + cross(v, t)}; }
    line shiftLeft(T dist) { return {v, c + dist * abs(v)}; }

    static bool inter(line l1, line l2, pt &out) {
        T d = cross(l1.v, l2.v);
        if (abs(d) < EPS) return false;
        out = (l2.v * l1.c - l1.v * l2.c) / d; 
        return true;
    }

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

    bool cmpProj(pt p, pt q) const {
        return dot(v, p) < dot(v, q);
    }
    
    bool operator < (const line& l) const {
        auto ang = [](pt p) { return atan2(p.y, p.x); };
        T a1 = ang(v), a2 = ang(l.v);
        if (abs(a1 - a2) > EPS) return a1 < a2;
        return c < l.c;
    }
};

/** * SEGMENTS 
 */
bool inDisk(pt a, pt b, pt p) {
    return dot(a - p, b - p) <= EPS;
}

bool onSegment(pt a, pt b, pt p) {
    return sgn(orient(a, b, p)) == 0 && inDisk(a, b, p);
}

bool properInter(pt a, pt b, pt c, pt d, pt &out) {
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

/** Ray */
struct ray {
    pt o, d; 

    ray(pt o, pt d) : o(o), d(d) {}

    static ray fromPoints(pt a, pt b) {
        return ray(a, b - a);
    }

    pt at(T t) const { return o + d * t; }

    bool onRay(pt p) const {
        if (abs(p - o) < EPS) return true;
        return sgn(cross(d, p - o)) == 0 && sgn(dot(d, p - o)) >= 0;
    }

    T dist(pt p) const {
        if (sgn(dot(d, p - o)) <= 0) return abs(p - o); 
        return abs(cross(d, p - o)) / abs(d);
    }

    T dist(const ray& r) const {
        pt out;
        if (intersect(r, out)) return 0;
        return min(dist(r.o), r.dist(o));
    }

    pt proj(pt p) const {
        T t = dot(p - o, d) / sq(d);
        if (t <= 0) return o; 
        return o + d * t;
    }

    bool isParallel(const ray& r) const {
        return abs(cross(d, r.d)) < EPS;
    }

    bool isCollinear(const ray& r) const {
        return isParallel(r) && abs(cross(d, r.o - o)) < EPS;
    }

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
T areaPolygon(const vector<pt>& p) {
    T area = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        area += cross(p[i], p[(i + 1) % n]);
    }
    return abs(area) / 2.0;
}

T areaPolygon2(vector<pt> p) {
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

bool inPolygon(const vector<pt>& p, pt a, bool strict = true) {
    int cnt = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        pt q = p[i], r = p[(i + 1) % n];
        if (onSegment(q, r, a)) return !strict;
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

T triangle_cos(pt a, pt b, pt c) {
    T ab = abs(b - a), ac = abs(c - a), bc = abs(c - b);
    return clamp((ab * ab + ac * ac - bc * bc) / (2 * ab * ac), (T)-1.0, (T)1.0);
}

T triangle_area(pt a, pt b, pt c) {
    return abs(cross(b - a, c - a)) / 2.0;
}

T triangle_area_side_angles(T side_a, T ang_A, T ang_B, T ang_C) {
    return (side_a * side_a * sin(ang_B) * sin(ang_C)) / (2 * sin(ang_A));
}

T triangle_area_R_angles(T R, T ang_A, T ang_B, T ang_C) {
    return 2 * R * R * sin(ang_A) * sin(ang_B) * sin(ang_C);
}

/* Circle */
struct circle {
    pt c; T r;
    circle() : c(0,0), r(0) {}
    circle(pt c, T r) : c(c), r(r) {}

    vector<pt> intersect(line l) const {
        pt proj = l.proj(c);
        T dist_sq = sq(proj - c);
        if (dist_sq > r * r + EPS) return {};
        if (abs(dist_sq - r * r) < EPS) return {proj};
        T offset = sqrt(max((T)0, r * r - dist_sq));
        pt dir = l.v / abs(l.v);
        return {proj + dir * offset, proj - dir * offset};
    }

    vector<pt> intersect(const circle& o) const {
        T d2 = sq(c - o.c), d = sqrt(d2);
        if (d > r + o.r + EPS || d < abs(r - o.r) - EPS || d < 1e-12) return {};
        T a = (r * r - o.r * o.r + d2) / (2 * d);
        T h = sqrt(max((T)0, r * r - a * a));
        pt p2 = c + a * (o.c - c) / d;
        pt vec = (o.c - c) * pt(0, h / d);
        return {p2 + vec, p2 - vec};
    }

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

    T intersection_area(circle other) const {
        T d = abs(other.c - c);
        if (d >= r + other.r - EPS) return 0;
        if (d <= abs(r - other.r) + EPS) return PI * min(r, other.r) * min(r, other.r);
        
        T a1 = acos(clamp((r * r + d * d - other.r * other.r) / (2 * r * d), (T)-1.0, (T)1.0));
        T a2 = acos(clamp((other.r * other.r + d * d - r * r) / (2 * other.r * d), (T)-1.0, (T)1.0));
        return r * r * a1 + other.r * other.r * a2 - r * d * sin(a1);
    }

    T sector_area_rad(T theta) const {
        return 0.5 * r * r * theta;
    }

    T sector_area_deg(T theta) const {
        return (theta / 360.0) * PI * r * r;
    }

    vector<pt> tangent_points(pt p) const {
        T d = abs(p - c);
        if (d < r - EPS) return {};
        if (abs(d - r) < EPS) return {p};
        T a = acos(clamp(r / d, (T)-1.0, (T)1.0)), b = arg(p - c);
        return {c + polar(r, b + a), c + polar(r, b - a)};
    }

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

/* Advanced Techniques */
void convex_hull(vector<pt> &pts, bool collinear_inc = true) {
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

bool isCCW(const vector<pt>& p) {
    int n = p.size();
    T area = 0;
    for (int i = 0; i < n; i++) {
        area += cross(p[i], p[(i + 1) % n]);
    }
    return area > EPS;
}

void reorder(vector<pt>& p) {
    int pos = 0;
    for (int i = 1; i < (int)p.size(); i++) {
        if (p[i].y < p[pos].y - EPS || (abs(p[i].y - p[pos].y) <= EPS && p[i].x < p[pos].x - EPS)) {
            pos = i;
        }
    }
    rotate(p.begin(), p.begin() + pos, p.end());
}

vector<pt> minkowskiSum(vector<pt> a, vector<pt> b) {
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

void takePoint(pt &p) {
    T xx, yy; cin >> xx >> yy;
    p = pt(xx, yy);
}

void solve() {
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(10);
    int t = 1; 
    while (t--) {
        solve();
    }
    return 0;
}