#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct Point {
    long double x, y;
};

Point reflect(Point p, double a, double b, double c) {
    double d = (a * p.x + b * p.y + c) / (a * a + b * b);
    Point r;
    r.x = p.x - 2 * a * d;
    r.y = p.y - 2 * b * d;
    return r;
}

double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void solve() {
    double a, b, c;
    Point p1, p2;
    cin >> a >> b >> c;
    cin >> p1.x >> p1.y;
    p1 = reflect(p1, a, b, c);
    cin >> p2.x >> p2.y;
    cout << distance(p1, p2) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t; 
    cout << fixed << setprecision(9);
    while (t--) solve();
}
