#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int MOD = 1e9 + 7;
const int INV2 = (MOD + 1) / 2;

int S(int x) {
    x %= MOD;
    return x * (x + 1) % MOD * INV2 % MOD;
}

int get_range_sum(int l, int r, int q, int type) {
    // type = 1: sum of q * (r - l + 1)
    if (type == 1) {
        return (q % MOD) * ((r - l + 1) % MOD) % MOD;
    // type = 2: sum of q * (S(r) - S(l - 1))
    } else {
        int sum_i = (S(r) - S(l - 1) + MOD) % MOD;
        return (q % MOD) * sum_i % MOD;
    }
}

// O(sqrt(N)))
int floor_sum(int N, int type) {
    int ans = 0;
    unsigned long long l = 1;

    while (l <= (unsigned long long)N) {
        unsigned long long q = N / l;
        unsigned long long r = N / q;

        ans = (ans + get_range_sum(l, r, q, type)) % MOD;
        l = r + 1;
    }

    return ans;
}