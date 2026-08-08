#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
using T = long double;
const T PI = acos(-1.0);
void solve() {
    int a, b, c, r;
    cin >> a >> b >> c >> r;
    T s = (a + b + c) / 2.0;
    T areaT = sqrtl(s * (s - a) * (s - b) * (s - c));
    T radius = areaT / s; // معلومة جديدة دي radius of incircle 
    T factor = (radius - r) / radius;
    T areaC = PI * r * r;
    T area = areaT;
    area *= (1 - (r * r) / (radius * radius));
    area += areaC;
    cout << area / areaT << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
