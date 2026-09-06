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
T sq(pt p) { return p.x * p.x + p.y * p.y; }

struct circle {
    pt c;
    T r;
    circle(pt c = {0, 0}, T r = 0) : c(c), r(r) {}
};

vector<pt> intersect(const circle& c1, const circle& c2) {
    T d2 = sq(c1.c - c2.c), d = sqrt(d2);
    if (d > c1.r + c2.r + EPS || d < abs(c1.r - c2.r) - EPS || d < 1e-12) return {};
    T a = (c1.r * c1.r - c2.r * c2.r + d2) / (2 * d);
    T h = sqrt(max((T)0, c1.r * c1.r - a * a));
    pt p2 = c1.c + a * (c2.c - c1.c) / d;
    pt vec = (c2.c - c1.c) * pt(0, h / d);
    return {p2 + vec, p2 - vec};
}

int count_unique(const vector<pt>& points) {
    vector<pt> points_;
    for (const auto& p : points) {
        bool ok = true;
        for (const auto& up : points_)
            if (abs(p - up) < EPS) ok = false;
        if (ok) points_.push_back(p);
    }
    return points_.size();
}

void solve() {
    int n;
    cin >> n;
    vector<circle> circles(n);
    for (int i = 0; i < n; i++) {
        T ox, oy, r;
        cin >> ox >> oy >> r;
        circles[i] = circle(pt(ox, oy), r);
    }
    int ans = n + 1;
    vector<pt> points;
    vector<vector<pt>> intersections(n);
    vector<int> parent(30);
    iota(all(parent), 0);
    auto find = [&](auto& find, int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(find, parent[u]);
    };

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto inters = intersect(circles[i], circles[j]);
            if (inters.empty()) continue;
            int u = find(find, i);
            int v = find(find, j);
            if (u != v) {
                parent[u] = v;
                ans--;
            }
            for (const auto& p : inters) {
                intersections[i].push_back(p);
                intersections[j].push_back(p);
                points.push_back(p);
            }
        }   
    }
    for (int i = 0; i < n; i++) {
        int k = count_unique(intersections[i]);
        ans += k;
    }
    ans -= count_unique(points);
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
