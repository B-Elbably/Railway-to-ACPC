#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const double PI = acos(-1.0L);
void solve() {
    int a, b, m, n, theta;
    cin >> a >> b >> m >> n >> theta;
    int g = gcd(m, n);
    n /= g;
    m /= g;
    double rad = theta * PI / 180.0;
    double x = a * cos(rad) + b * sin(rad);
    double y = a * sin(rad) + b * cos(rad);
    int k = max(ceil(x / m), ceil(y / n));
    cout << m * k << " " << n * k << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
