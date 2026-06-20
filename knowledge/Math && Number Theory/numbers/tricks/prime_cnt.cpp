#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct PrimeCount {
    int n, r;
    vector<int> S_large, S_small;

    PrimeCount(int n) : n(n) {
        if (n < 2) {
            r = 0;
            return;
        }
        r = sqrt(n);
        S_large.resize(r + 1);
        S_small.resize(r + 1);
        for (int i = 1; i <= r; ++i) {
            S_large[i] = n / i - 1;
            S_small[i] = i - 1;
        }
        for (int p = 2; p <= r; ++p) {
            if (S_small[p] == S_small[p - 1]) continue;
            int pcnt = S_small[p - 1];
            int q = p * p;
            int max_i = min(r, n / q);
            for (int i = 1; i <= max_i; ++i) {
                int d = i * p;
                S_large[i] -= ((d <= r) ? S_large[d] : S_small[n / d]) - pcnt;
            }
            for (int i = r; i >= q; --i) {
                S_small[i] -= S_small[i / p] - pcnt;
            }
        }
    }

    int get(int x) {
        if (x < 2) return 0;
        if (x <= r) return S_small[x];
        return S_large[n / x];
    }
};