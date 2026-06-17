#include <bits/stdc++.h>
using namespace std;
/*
    Notes:
    - digits(n) = floor(log10(n)) + 1
    - digits(n!) = floor(log10(2πn)/2 + n(log10(n) - log10(e))) + 1
    - Trailing zeros in n! = floor(n/5) + floor(n/25) + floor(n/125) + ...
    - log(n!) = log(1) + log(2) + ... + log(n)
*/
const int MAXN = 1e6 + 5;

vector<int> primes;
bool is_prime[MAXN];

void sieve(int n) {
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++)
        if (is_prime[i])
            primes.push_back(i);
}

long long factorial_prime_exp(long long n, long long p) {
    long long res = 0;
    while (n) {
        res += n / p;
        n /= p;
    }
    return res;
}

map<long long, long long> factorial_factorization(long long n) {
    map<long long, long long> factorization;
    for (int p : primes) {
        if (p > n) break;
        factorization[p] = factorial_prime_exp(n, p);
    }
    return factorization;
}

int factorial_digits(long long n) {
    if (n <= 1) return 1;
    long double x = n * log10((long double)n / M_E) + 0.5 * log10(2 * M_PI * n);
    return floor(x) + 1;
}

long long trailing_zeros(long long n) {
    long long res = 0;
    for (long long i = 5; i <= n; i *= 5)
        res += n / i;
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(MAXN-1);

    long long n;
    cin >> n;

    cout << "Digits in " << n << "! = " << factorial_digits(n) << "\n";
    cout << "Trailing zeros in " << n << "! = " << trailing_zeros(n) << "\n";

    auto fac_fact = factorial_factorization(n);
    cout << "Prime factorization of " << n << "!:\n";
    for (auto &[p, exp] : fac_fact) {
        cout << p << "^" << exp << " ";
    }
    cout << "\n";
}
