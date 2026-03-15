// AI-Generated
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 5, M = 1e9 + 7;
int fac[N], inv[N], pre[N], suf[N], y[N];

int exp(int x, int n) {
    int res = 1; x %= M;
    while (n > 0) {
        if (n % 2 == 1) res = (res * x) % M;
        x = (x * x) % M; n /= 2;
    }
    return res;
}

void build(int d) {
    fac[0] = 1;
    for (int i = 1; i <= d; i++) fac[i] = (fac[i - 1] * i) % M;
    inv[d] = exp(fac[d], M - 2);
    for (int i = d; i > 0; i--) inv[i - 1] = (inv[i] * i) % M;
}

void solve() {
    int n, k; cin >> n >> k;
    int d = k + 1;
    build(d);

    // 1. Point generation
    y[0] = 0;
    for (int i = 1; i <= d; i++) y[i] = (y[i - 1] + exp(i, k)) % M;
    if (n <= d) { cout << y[n] << endl; return; }

    // 2. Prefix and Suffix products
    pre[0] = n % M;
    for (int i = 1; i <= d; i++) pre[i] = (pre[i - 1] * ((n - i) % M)) % M;
    suf[d] = (n - d) % M;
    for (int i = d - 1; i >= 0; i--) suf[i] = (suf[i + 1] * ((n - i) % M)) % M;

    // 3. Lagrange Calculation
    int ans = 0;
    for (int i = 0; i <= d; i++) {
        int num = 1;
        if (i > 0) num = (num * pre[i - 1]) % M;
        if (i < d) num = (num * suf[i + 1]) % M;

        int den = (inv[i] * inv[d - i]) % M;
        if ((d - i) % 2 == 1) den = (M - den) % M;

        ans = (ans + y[i] * num % M * den) % M;
    }
    cout << (ans + M) % M << endl;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}