#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
using T = long double;
const T PI = acos((T)-1.0);
static T areaRegular(int n, T side) {
    return (T)n * side * side / (T)4.0 / tan(PI / (T)n);
} 


void solve() {
    int n, s;
    cin >> n >> s;
    T area = areaRegular(n, s);
    area /= (T)n;
    T rad = 360.0 / n * PI / 180.0;
    T r2 = area * 2 / sin(rad);
    T a = PI * r2;
    cout << a << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(9);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
