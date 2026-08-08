#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
using T = long double;
const T PI = acos(-1.0);

// T getC(T a, T b, T area) {
//     double val = (a * b) * (a * b) - 4.0 * area * area;
//     if (val < 0) val = 0;
//     double term = 2.0 * sqrt(val);
//     return sqrt(a * a + b * b - term);
// }

// T angle(T a, T b, T c) {
//     return acos((b * b + c * c - a * a) / (2.0 * b * c));
// }

void solve() {
    int ab, ac, a1, a2;
    cin >> ab >> ac >> a1 >> a2;

    T ratio = sqrt((T)a2 / (T)a1);
    T x = ab * ratio - ac;
    T y = ac * ratio - ab;  
    cout << fixed << setprecision(10) << x << " " << y << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
