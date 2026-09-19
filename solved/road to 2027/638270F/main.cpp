#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
using T = long double;
const T EPS = 1e-9;
const T PI = acos(-1.0);


void solve() {
    int x1, y1;
    cin >> x1 >> y1;
    int x2, y2;
    cin >> x2 >> y2;
    int area;
    cin >> area;
    T r = sqrt(area);
    T ag = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    T gd = r - ag;
    T area2 = 0.5 * gd * gd;
    cout << area2 << '\n';
    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
