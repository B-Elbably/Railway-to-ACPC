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

struct circle {
    pt c; T r;
    circle() : c(0,0), r(0) {}
    circle(pt c, T r) : c(c), r(r) {}
    
    T intersection_area(circle other) const {
        T d = abs(other.c - c);
        if (d >= r + other.r - EPS) return 0;
        if (d <= abs(r - other.r) + EPS) return PI * min(r, other.r) * min(r, other.r);
        
        T a1 = acos(clamp((r * r + d * d - other.r * other.r) / (2 * r * d), (T)-1.0, (T)1.0));
        T a2 = acos(clamp((other.r * other.r + d * d - r * r) / (2 * other.r * d), (T)-1.0, (T)1.0));
        return r * r * a1 + other.r * other.r * a2 - r * d * sin(a1);
    }
};
int cnt = 0;
void solve() {
    cnt++;
    circle c1, c2;
    int xx, yy, r;
    cin >> xx >> yy >> r;
    c1 = circle(pt(xx, yy), r);
    cin >> xx >> yy >> r;
    c2 = circle(pt(xx, yy), r);
    cout << "Case " << cnt << ": ";
    cout << c1.intersection_area(c2) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(7);
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
