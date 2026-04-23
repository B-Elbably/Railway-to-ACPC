#include <bits/stdc++.h>
using namespace std;
// import from ex_gcd.cpp
#include "ex_gcd.cpp"

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

/*
    NOTE: Congruence
    a ≡ b (mod n)
    a = b + q * n
*/

/*
    NOTE: Congruence properties
    ax ≡ ay (mod n), gcd(a, n) = d
    then x ≡ y (mod n/d)
*/

/*
    NOTE: NOTES
    // if p :=> (x + y) ^ p ≡ x ^ p + y ^ p (mod p)

    NOTE: ==========
    a ≡ b (mod n), c ≡ d (mod n)
    then:
    a + c ≡ b + d (mod n)
    a * c ≡ b * d (mod n)
    a - c ≡ b - d (mod n)
*/


/*
    NOTE: Linear Modular Equation
    ax ≡ b (mod n)
    Let g = gcd(a, n)
*/

// returns all solutions of ax ≡ b (mod n)
vector<int> modular_equation(int a, int b, int n) {
    int g = gcd(a, n);
    if (b % g) return {};
    int x, y;
    extended_gcd(a / g, n / g, x, y);
    n /= g;
    x = (x % n + n) % n;
    x = (x * (((b / g) % n) + n)) % n;
    vector<int> ans(g);
    for (int i = 0; i < g; ++i) ans[i] = x + i * n;
    return ans;
}