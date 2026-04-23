#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'


/* 
    NOTE: Extended Euclidean Algorithm
    ax + by = gcd(a, b)
    x0, y0 is one particular solution if c % gcd(a, b) == 0

    x = x0 + (b / g) * t
    y = y0 - (a / g) * t
*/
int extended_gcd(int a, int b, int &x, int &y) {
    if (a < 0) {
        int r = extended_gcd(-a, b, x, y);
        x = -x;
        return r;
    }
    if (b < 0) {
        int r = extended_gcd(a, -b, x, y);
        y = -y;
        return r;
    }
    if (b == 0) {
        x = 1,y = 0;
        return a;
    }
    int x1, y1;
    int g = extended_gcd(b, a % b, x1, y1);
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


// TODO: find any solution of ax + by = c
int linear_diophantine(int a, int b, int c, int &x, int &y) {
    int g = extended_gcd(a, b, x, y);
    if (c % g != 0) {
        return -1;
    }
    int scale = c / g;
    x *= scale;
    y *= scale;
    return g; 
}


int32_t main() {
    int a, b, c;
    cin >> a >> b >> c;

    int x, y;
    int g = extended_gcd(a, b, x, y);

    if (c % g != 0) {
        cout << -1 << '\n';
        return 0;
    }

    int scale = c / g;
    x *= scale;
    y *= scale;

    cout << x << " " << y << '\n';
    return 0;
}
