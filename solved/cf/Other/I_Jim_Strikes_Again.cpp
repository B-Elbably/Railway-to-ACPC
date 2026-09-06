#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using T = long double;
const T EPS = 1e-12;

T orient(const pair<T, T>& a, const pair<T, T>& b, const pair<T, T>& c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

T cross(const pair<T, T>& a, const pair<T, T>& b) {
    return a.first * b.second - a.second * b.first;
}

pair<T, T> lineIntersection(const pair<T, T>& a1, const pair<T, T>& a2, const pair<T, T>& b1, const pair<T, T>& b2) {
    T A1 = a2.second - a1.second;
    T B1 = a1.first - a2.first;
    T C1 = A1 * a1.first + B1 * a1.second;

    T A2 = b2.second - b1.second;
    T B2 = b1.first - b2.first;
    T C2 = A2 * b1.first + B2 * b1.second;

    T det = A1 * B2 - A2 * B1;
    if (abs(det) < EPS) {
        return {numeric_limits<T>::infinity(), numeric_limits<T>::infinity()};
    } else {
        return {(B2 * C1 - B1 * C2) / det, (A1 * C2 - A2 * C1) / det};
    }
}

T areaPolygon2(vector<pair<T, T>> p) {
    int n = p.size();
    if (n < 3) return 0;
    T area = 0;
    for (int i = 0; i < n; i++)
        area += (p[i].first * p[(i + 1) % n].second - p[(i + 1) % n].first * p[i].second);
    return abs(area) / 2.0;
}

vector<pair<T, T>> kernel_of_convex(const vector<pair<T, T>>& poly) {
    vector<pair<T, T>> input = poly;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        pair<T, T> a = poly[i], b = poly[(i + 1) % n];
        vector<pair<T, T>> output;
        int M = input.size();
        for (int j = 0; j < M; j++) {
            pair<T, T> c = input[j], d = input[(j + 1) % M];
            double side_c = orient(a, b, c);
            double side_d = orient(a, b, d);
            if (side_c >= -EPS) {
                output.push_back(c);
                if (side_d < -EPS) {
                    output.push_back(lineIntersection(a, b, c, d));
                }
            } else if (side_d >= -EPS) {
                output.push_back(lineIntersection(a, b, c, d));
            }
        }
        input = output;
    }
    return input;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<T, T>> ps(n);
    for (auto &p : ps) cin >> p.first >> p.second;
    vector<pair<T, T>> poly = kernel_of_convex(ps);
    T area = areaPolygon2(ps);
    T area2 = areaPolygon2(poly);
    cout << fixed << setprecision(12) << area2 / area << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}