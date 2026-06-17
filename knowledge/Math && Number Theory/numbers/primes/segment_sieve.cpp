#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MAX_LIMIT = 46341; 
vector<int> primes;

void precompute_primes() {
    vector<bool> is_prime(MAX_LIMIT + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= MAX_LIMIT; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= MAX_LIMIT; i += p)
                is_prime[i] = false;
        }
    }
    for (int p = 2; p <= MAX_LIMIT; p++) {
        if (is_prime[p]) primes.push_back(p);
    }
}

void solve() {
    int L, U;
    cin >> L >> U;

    vector<bool> is_prime(U - L + 1, true);
    if (L == 1) is_prime[0] = false;

    for (int p : primes) {
        if (p * p > U) break;
        int start = max(p * p, (L + p - 1) / p * p);
        for (int j = start; j <= U; j += p) {
            is_prime[j - L] = false;
        }
    }

    for (int i = 0; i <= U - L; i++) {
        if (is_prime[i]) {
            cout << L + i << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute_primes();

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}