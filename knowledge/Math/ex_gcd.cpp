#include <bits/stdc++.h>
using namespace std;

/* 
    NOTE: Extended Euclidean Algorithm
    ax + by = gcd(a, b)
    x0, y0 is one particular solution if c % gcd(a, b) == 0

    x = x0 + (b / g) * t
    y = y0 - (a / g) * t
*/
long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1,y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

/* 
    NOTE: Bézout's Identity
    gcd(a, b) = a*x + b*y

    Let g = gcd(a, b), and (x0, y0) one solution.
    All solutions:
        x = x0 + (b/g)*t
        y = y0 - (a/g)*t
    t = any integer
*/

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    long long x, y;
    long long g = extended_gcd(a, b, x, y);

    if (c % g != 0) {
        cout << -1 << '\n';
        return 0;
    }

    long long scale = c / g;
    x *= scale;
    y *= scale;

    cout << x << " " << y << '\n';
    return 0;
}
