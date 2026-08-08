#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
using T = long double;
const T PI = acos((T)-1.0);


struct RegularPyramid {
    int n;       // Number of base sides
    double a;    // Base side length
    double h;    // Height

    double base_area() const {
        return (n * a * a) / (4.0 * std::tan(PI / n));
    }

    double volume() const {
        return (1.0 / 3.0) * base_area() * h;
    }

    double circumradius() const {
        return a / (2.0 * std::sin(PI / n));
    }

    double inradius() const {
        return a / (2.0 * std::tan(PI / n));
    }

    double lateral_edge() const {
        double R = circumradius();
        return std::sqrt(h * h + R * R);
    }

    double slant_height() const {
        double r = inradius();
        return std::sqrt(h * h + r * r);
    }

    double lateral_area() const {
        return 0.5 * n * a * slant_height();
    }

    double total_surface_area() const {
        return base_area() + lateral_area();
    }

    // Factory method: build pyramid when all edges (base + lateral) are equal
    static RegularPyramid from_equal_edges(int n, double l) {
        double R = l / (2.0 * std::sin(PI / n));
        double h = std::sqrt(l * l - R * R);
        return {n, l, h};
    }
};


T areaRegular(int n, T side) {
    return (T)n * side * side / (T)4.0 / tan(PI / (T)n);
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    RegularPyramid p3 = RegularPyramid::from_equal_edges(3, a);
    RegularPyramid p4 = RegularPyramid::from_equal_edges(4, b);
    RegularPyramid p5 = RegularPyramid::from_equal_edges(5, c);
    T ans = 0;
    ans += p3.volume();
    ans += p4.volume();
    ans += p5.volume();
    cout << fixed << setprecision(10) << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
