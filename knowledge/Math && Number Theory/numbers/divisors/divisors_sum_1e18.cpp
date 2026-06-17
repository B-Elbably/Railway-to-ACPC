#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

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
    int s = 0;
    while (d % 2 == 0) { d /= 2; s++; }
    ll x = power(a, d, n);
    if (x == 1 || x == n - 1) return true;
    for (int r = 1; r < s; r++) {
        x = (ll)((int128)x * x % n);
        if (x == n - 1) return true;
    }
    return false;
}

bool is_prime(ll n) {
    if (n < 2) return false;
    static const vector<int> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    for (int a : bases) {
        if (n == a) return true;
        if (!miller_rabin(n, a)) return false;
    }
    return true;
}

ll gcd(ll a, ll b) {
    while (b) { a %= b; swap(a, b); }
    return a;
}

ll pollard_rho(ll n) {
    if (n % 2 == 0) return 2;
    if (is_prime(n)) return n;
    static mt19937_64 rng(1337);
    uniform_int_distribution<ll> dist(2, n - 1);
    ll x = dist(rng), y = x, c = dist(rng), g = 1;
    while (g == 1) {
        x = (ll)(((int128)x * x + c) % n);
        y = (ll)(((int128)y * y + c) % n);
        y = (ll)(((int128)y * y + c) % n);
        g = gcd(abs(x - y), n);
        if (g == n) return pollard_rho(n);
    }
    return g;
}

void factorize(ll n, vector<ll>& f) {
    if (n == 1) return;
    if (is_prime(n)) { f.push_back(n); return; }
    ll d = pollard_rho(n);
    factorize(d, f);
    factorize(n / d, f);
}

// O(sqrt(sqrt(n))) for n <= 1e18
void solve() {
    ll n;
    cin >> n;
    if (n == 1) { cout << 0 << "\n"; return; }
    vector<ll> f;
    factorize(n, f);
    sort(f.begin(), f.end());
    ll ans = 1;
    for (size_t i = 0; i < f.size(); ) {
        ll p = f[i], term = 1, p_pow = 1;
        while (i < f.size() && f[i] == p) {
            p_pow *= p;
            term += p_pow;
            i++;
        }
        ans *= term;
    }
    cout << ans - n << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}