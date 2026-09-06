#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
using T = long double;
#define pt complex<T>
#define X real()
#define Y imag()
const T EPS = 1e-9;

struct Circle {
    pt c;
    T r;
    Circle() : c(0, 0), r(0) {}
    Circle(pt c, T r) : c(c), r(r) {}
};

pair<pt, T> circumcircle(pt a, pt b, pt c) {
    T d = 2.0 * (a.X * (b.Y - c.Y) + b.X * (c.Y - a.Y) + c.X * (a.Y - b.Y));
    if (abs(d) < EPS) return {(a + b) / (T)2.0, abs(a - b) / (T)2.0};
    T ux = (norm(a) * (b.Y - c.Y) + norm(b) * (c.Y - a.Y) + norm(c) * (a.Y - b.Y)) / d;
    T uy = (norm(a) * (c.X - b.X) + norm(b) * (a.X - c.X) + norm(c) * (b.X - a.X)) / d;
    pt center(ux, uy);
    return {center, abs(center - a)};
}

Circle minimumEnclosingCircle(vector<pt>& p) {
    if (p.empty()) return Circle();
    mt19937 rng(1337);
    shuffle(p.begin(), p.end(), rng);
    Circle c(p[0], 0);
    int n = p.size();
    for (int i = 0; i < n; i++) {
        if (abs(p[i] - c.c) > c.r + EPS) {
            c = Circle(p[i], 0);
            for (int j = 0; j < i; j++) {
                if (abs(p[j] - c.c) > c.r + EPS) {
                    c = Circle((p[i] + p[j]) / (T)2.0, abs(p[i] - p[j]) / (T)2.0);
                    for (int k = 0; k < j; k++) {
                        if (abs(p[k] - c.c) > c.r + EPS) {
                            auto res = circumcircle(p[i], p[j], p[k]);
                            c = Circle(res.first, res.second);
                        }
                    }
                }
            }
        }
    }
    return c;
}

void solve() {
    int n;
    cin >> n;
    T k;
    cin >> k;
    vector<pt> points(n);
    for (int i = 0; i < n; i++) {
        int xx, yy;
        cin >> xx >> yy;
        points[i] = pt(xx, yy);
    }
    Circle mec = minimumEnclosingCircle(points);
    cout << mec.r + k << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    while (t--) solve();
    return 0;
}