#include <bits/stdc++.h>
using namespace std;

/** * BASIC SETUP & UTILS 
 */
using T = long double;
using pt = complex<T>;
using LL = long long;
using pti = complex<LL>;

#define x real()
#define y imag()

const T EPS = 1e-9;
const T PI = acos((T)-1.0);

int sgn(T val) { return (val > EPS) - (val < -EPS); } // compare with tolerance
T sq(pt p) { return p.x * p.x + p.y * p.y; } // squared magnitude
T dot(pt v, pt w) { return v.x * w.x + v.y * w.y; } // dot product
T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; } // cross product (2D "determinant")
T orient(pt a, pt b, pt c) { return cross(b - a, c - a); } // >0 CCW, <0 CW, =0 collinear 

// Integer overloads to guarantee zero precision loss
LL dot(pti v, pti w) { return v.x * w.x + v.y * w.y; }
LL cross(pti v, pti w) { return v.x * w.y - v.y * w.x; }
LL orient(pti a, pti b, pti c) { return cross(b - a, c - a); }

// Perpendicular vector (90 deg CCW)
pt perp(pt p) { return {-p.y, p.x}; }
pti perp(pti p) { return {-p.y, p.x}; }
bool isPerp(pt v, pt w) { return abs(dot(v, w)) < EPS; }
bool isParallel(pt v, pt w) { return abs(cross(v, w)) < EPS; }

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

bool inDisk(pti a, pti b, pti p) {
    return dot(a - p, b - p) <= 0;
}

bool onSegment(pti a, pti b, pti p) {
    return orient(a, b, p) == 0 && inDisk(a, b, p);
}

int inPolygon(const vector<pti>& p, pti a, bool strict = true) {
    int cnt = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        pti q = p[i], r = p[(i + 1) % n];
        if (onSegment(q, r, a)) return -1;
        bool up = (q.y <= a.y && a.y < r.y);
        bool down = (r.y <= a.y && a.y < q.y);
        if ((up || down) && ((orient(q, r, a) > 0) == (q.y < r.y))) {
            cnt++;
        }
    }
    return (cnt & 1) ? 1 : 0;
}

void takePoint(pti &p) {
    LL xx, yy; cin >> xx >> yy;
    p = pti(xx, yy);
}

void solve() {
    int n, m; cin >> n >> m;
    vector<pti> polygon(n);
    for (int i = 0; i < n; i++) takePoint(polygon[i]);
    vector<string> results = {"BOUNDARY", "OUTSIDE", "INSIDE"};
    for (int i = 0; i < m; i++) {
        pti query; takePoint(query);
        cout << results[inPolygon(polygon, query) + 1] << "\n";
    }
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
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}