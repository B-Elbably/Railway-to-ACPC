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

T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; } // cross product (2D "determinant")

T areaPolygon(const vector<pt>& p) {
    T area = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        area += cross(p[i], p[(i + 1) % n]);
    }
    return abs(area) / 2.0;
}

void takePoint(pt &p) {
    int xx, yy; cin >> xx >> yy;
    p = {xx, yy};
}
void solve() {
    int n; cin >> n;
    vector<pt> points(n);
    for (int i = 0; i < n; i++) {
        takePoint(points[i]);
    }
    cout << areaPolygon(points) << "\n";
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string filename;
    filename = "area";
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