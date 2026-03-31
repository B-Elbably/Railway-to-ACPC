#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 1e6; 
vector<int> fac(N + 1), inv(N + 1);

int exp(int x, int n, int m) {
    x %= m;
    int res = 1;
    while (n > 0) {
        if (n % 2) res = (res * x) % m;
        x = (x * x) % m;
        n /= 2;
    }
    return res;
}

void factorial(int p) {
    fac[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = (fac[i - 1] * i) % p;
    }
}

void inverses(int p) {
    inv[N] = exp(fac[N], p - 2, p);
    for (int i = N; i > 0; i--) {
        inv[i - 1] = (inv[i] * i) % p;
    }
}

int choose(int n, int r, int p) {
    if (r < 0 || r > n) return 0;
    return fac[n] * inv[r] % p * inv[n - r] % p;
}

vector<int> derangements(int N, int M) {
    vector<int> D(N + 1);
    D[0] = 1; D[1] = 0;
    for (int k = 2; k <= N; k++) {
        D[k] = ((k - 1) * (D[k - 1] + D[k - 2])) % M;
    }
    vector<int> res(D.begin() + 1, D.end());
    return res;
}

void solve() {
    int N, M;
    cin >> N >> M;

    factorial(M);
    inverses(M);
    vector<int> result = derangements(N, M);

    for (int x : result) cout << x << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}