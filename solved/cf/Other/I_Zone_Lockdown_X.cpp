#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using T = long double;
using pt = complex<T>;
#define x real()
#define y imag()
const T EPS = 1e-9;
const T PI = acos((T)-1.0);

T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; } // cross product (2D "determinant")
T orient(pt a, pt b, pt c) { return cross(b - a, c - a); } // >0 CCW, <0 CW, =0 collinear 

void convex_hull(vector<pt> &pts, bool collinear_inc = true) {
    if (pts.size() <= 1)
        return;
    sort(pts.begin(), pts.end(), [](const pt& a, const pt& b) {
        if (fabs(a.x - b.x) > EPS)
            return a.x < b.x;
        return a.y < b.y;
    });
    vector<pt> hull;
    auto bad = [&](const pt& a, const pt& b, const pt& c) {
        double o = orient(a, b, c);

        if (collinear_inc)
            return o < -EPS;   // remove only clockwise
        else
            return o <= EPS;   // remove clockwise + collinear
    };

    // lower hull
    for (const pt& p : pts) {
        while (hull.size() >= 2 &&
                bad(hull[hull.size() - 2], hull.back(), p)) {
            hull.pop_back();
        }
        hull.push_back(p);
    }

    // upper hull
    int t = hull.size() + 1;
    for (int i = (int)pts.size() - 2; i >= 0; --i) {
        while ((int)hull.size() >= t &&
                bad(hull[hull.size() - 2], hull.back(), pts[i])) {
            hull.pop_back();
        }
        hull.push_back(pts[i]);
    }

    hull.pop_back();

    pts = hull;
}
struct Circle { pt c; T r; };

Circle make_circle(pt a, pt b) {
    return {(a + b) / (T)2.0, abs(a - b) / (T)2.0};
}

Circle make_circle(pt a, pt b, pt c) {
    pt bb = b - a, cc = c - a;
    T B = norm(bb), C = norm(cc), D = 2 * cross(bb, cc);
    pt center = a + pt(cc.y * B - bb.y * C, bb.x * C - cc.x * B) / D;
    return {center, abs(center - a)};
}

Circle welzl(vector<pt>& p, vector<pt> r, int n) {
    if (n == 0 || r.size() == 3) {
        if (r.empty()) return {{0, 0}, 0};
        if (r.size() == 1) return {r[0], 0};
        if (r.size() == 2) return make_circle(r[0], r[1]);
        return make_circle(r[0], r[1], r[2]);
    }
    Circle c = welzl(p, r, n - 1);
    if (abs(c.c - p[n - 1]) <= c.r + EPS) return c;
    r.push_back(p[n - 1]);
    return welzl(p, r, n - 1);
}

T min_bounding_circle_area(vector<pt> pts) {
    if (pts.empty()) return 0.0;
    mt19937 gen(random_device{}());
    shuffle(all(pts), gen);
    Circle c = welzl(pts, {}, pts.size());
    return PI * c.r * c.r;
}

void takePoint(pt &p) {
    T xx, yy; cin >> xx >> yy;
    p = pt(xx, yy);
}


void solve() {
    int n;
    cin >> n;
    T k;
    cin >> k;
    vector<pt> c(n);
    for (int i = 0; i < n; i++) {
        takePoint(c[i]);
    } 
    vector<pt> poly = c;
    convex_hull(poly);
    T area = min_bounding_circle_area(poly);
    area /= PI;
    cout << sqrt(area) + k << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(12);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
