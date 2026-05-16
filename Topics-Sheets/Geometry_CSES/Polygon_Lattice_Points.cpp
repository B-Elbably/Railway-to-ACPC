#include <bits/stdc++.h>
using namespace std;

using T = long long;
using pt = complex<T>;
#define x real()
#define y imag()

const T EPS = 1e-9;

T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; } // cross product (2D "determinant")

T areaPolygon(const vector<pt>& p) {
    T area = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        area += cross(p[i], p[(i + 1) % n]);
    }
    return abs(area); // >0: CCW, <0: CW
}

void takePoint(pt &p) {
    T xx, yy; cin >> xx >> yy;
    p = pt(xx, yy);
}

int n;
T lattice(pt a, pt b) {
    return (__gcd(abs(a.x - b.x), abs(a.y - b.y)));
}

T calcBoundary(const vector<pt>& p) {
    T ans = 0;
    for (int i = 0; i < n; i++) {
        ans += lattice(p[i], p[(i + 1) % n]);
    }
    return ans;
}

void solve() {
    cin >> n;
    vector<pt> p(n);
    for (int i = 0; i < n; i++) takePoint(p[i]);
    // area = internal + boundary / 2 - 1

    T area = abs(areaPolygon(p));
    T boundary = calcBoundary(p);
    T interior = area - boundary + 2;
    cout << interior / 2 << " " << boundary << "\n";
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