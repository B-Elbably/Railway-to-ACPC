#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    int A, B, C;
    A = (m / a) * 6;
    B = (m / b) * 6;
    C = (m / c) * 6;
    int nnn = (m / lcm(a , b)) * 3;
    A -= nnn;
    B -= nnn;
    int nnn2 = (m / lcm(a , c)) * 3;
    A -= nnn2;
    C -= nnn2;
    int nnn3 = (m / lcm(b , c)) * 3;
    B -= nnn3;
    C -= nnn3;
    int nnn4 = (m / lcm(a , lcm(b , c))) * 2;
    A += nnn4;
    B += nnn4;
    C += nnn4;
    cout << A << " " << B << " " << C << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
