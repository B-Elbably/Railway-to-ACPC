// https://codeforces.com/gym/100753 
// F - Divisions
#include <bits/stdc++.h>
using namespace std;

typedef __int128_t int128;
typedef long long ll;

ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (ll)((int128)res * base % mod);
        base = (ll)((int128)base * base % mod);
        exp /= 2;
    }
    return res;
}

bool miller_rabin(ll n, int a) {
    if (a % n == 0) return true;
    ll d = n - 1;
    while (d % 2 == 0) d /= 2;
    ll x = power(a, d, n);
    if (x == 1 || x == n - 1) return true;
    while (d != n - 1) {
        x = (ll)((int128)x * x % n);
        d *= 2;
        if (x == n - 1) return true;
        if (x == 1) return false;
    }
    return false;
}

bool is_prime(ll n) {
    if (n < 2) return false;
    static const vector<ll> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    for (ll a : bases) {
        if (n == a) return true;
        if (!miller_rabin(n, a)) return false;
    }
    return true;
}

ll pollard_rho(ll n) {
    if (n % 2 == 0) return 2;
    if (is_prime(n)) return n;
    ll x = 2, y = 2, d = 1, c = 1;
    auto f = [&](ll x, ll c, ll n) { return (ll)(((int128)x * x + c) % n); };
    while (d == 1) {
        x = f(x, c, n);
        y = f(f(y, c, n), c, n);
        d = std::gcd(abs(x - y), n);
        if (d == n) { x = 2; y = 2; c++; d = 1; }
    }
    return d;
}

void factorize(ll n, map<ll, int>& factors) {
    if (n == 1) return;
    if (is_prime(n)) {
        factors[n]++;
        return;
    }
    ll d = pollard_rho(n);
    factorize(d, factors);
    factorize(n / d, factors);
}

ll count_divisors(ll n) {
    map<ll, int> factors;
    factorize(n, factors);
    ll ans = 1;
    for (auto const& [p, e] : factors) ans *= (e + 1);
    return ans;
}

int main() {
    ll n; cin >> n;
    cout << count_divisors(n) << endl;
    return 0;
}