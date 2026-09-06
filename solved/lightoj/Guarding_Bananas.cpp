#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
using T = long double;
const T EPS = 1e-9;
const T PI = acos(-1.0);
using pt = complex<T>;
#define x real()
#define y imag()

T sq(pt p) { return p.x * p.x + p.y * p.y; }
T orient(pt a, pt b, pt c) { return (b - a).x * (c - a).y - (b - a).y * (c - a).x; }
T dot(pt v, pt w) { return v.x * w.x + v.y * w.y; }
T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; }

 T angle(pt v, pt w) {
        if (abs(v) < EPS || abs(w) < EPS) return 0;
        return acos(clamp(dot(v, w) / (abs(v) * abs(w)), (T)-1.0, (T)1.0));
    }   
static void convex_hull(vector<pt> &pts, bool collinear_inc = true) {
        if (pts.size() <= 1) return;
        sort(pts.begin(), pts.end(), [](const pt& a, const pt& b) {
            if (fabs(a.x - b.x) > EPS) return a.x < b.x;
            return a.y < b.y;
        });
        pts.erase(unique(pts.begin(), pts.end(), [](const pt& a, const pt& b) {
    return a.x == b.x && a.y == b.y;
}), pts.end());
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

    int tc = 0;
void solve() {
    int n;
    cin >> n;
    vector<pt> points(n);
    for (int i = 0; i < n; i++) {
        int xx, yy;
        cin >> xx >> yy;
        points[i] = pt(xx, yy);
    }
//     points.erase(unique(points.begin(), points.end(), [](const pt& a, const pt& b) {
//     return fabsl(a.x - b.x) < EPS &&
//            fabsl(a.y - b.y) < EPS;
// }), points.end());
    convex_hull(points, 0);
    // reverse(points.begin(), points.end());
    if (points.size() < 3) {
        cout << "Case " << ++tc << ": 0.0000000000" << endl;
        return;
    }
    T ans = 360.0L;
    n = points.size();
    for (int i = 0; i < (int)points.size(); i++) {
        pt a = points[i];
        pt b = points[(i + 1) % n];
        pt c = points[(i + 2) % n];
        T ang = angle(b - a, c - a) * 180.0L / PI;
        ans = min(ans, ang);
    }
    // if (360.0 - ans < EPS) ans = 0.0;
    // if (ans == 360.0) ans = 0.0;
    cout << "Case " << ++tc << ": ";
    cout << fixed << setprecision(10) << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
