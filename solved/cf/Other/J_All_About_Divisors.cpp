#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e7 + 7;
const int N = 1e6 + 5;
int inv2 = 5e6 + 4;
int prime[N];

int get_exponent(int n, int p) {
    int count = 0;
    while (n > 0) {
        count += n / p;
        n /= p;
    }
    return count;
}

void build() {
    for (int i = 2; i < N; ++i) prime[i] = 1;
    for (int i = 2; i * i < N; ++i) {
        if (!prime[i]) continue;
        for (int j = i * i; j < N; j += i) prime[j] = 0;
    }
}

void solve(int n) {
    if (n == 0) return;
    ll ans = 1;
    for (int p = 2; p <= n; ++p) {
        if (!prime[p]) continue;
        ll a_p = get_exponent(n, p);
        ll term = ((a_p + 1) % MOD) * ((a_p + 2) % MOD) % MOD;
        term = (term * inv2) % MOD;
        ans = (ans * term) % MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    int n;
    while (cin >> n) {
        solve(n);
    }
    return 0;
}