#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

ll modPow(ll base, ll exp) {
    ll result = 1;
    base = base % MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp = exp / 2;
    }
    return result;
}

ll sumPows(ll a, ll k) { // a^1 + a^2 + ... + a^k
    if (k == 0) return 0;
    if (k % 2 == 1) 
        return (sumPows(a, k - 1) + modPow(a, k)) % MOD;
    ll half = sumPows(a, k / 2);
    return (half + (modPow(a, k / 2) * half) % MOD) % MOD;

}