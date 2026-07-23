#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
vector<int> primes;

void build() {
    vector<bool> isPrime(N, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i < N; i++)
        if (isPrime[i])
            primes.push_back(i);
}

int phi(int n) {
    int ans = n;
    int x = n;
    for (int p : primes) {
        if (1LL * p * p > x) break;
        if (x % p == 0) {
            ans -= ans / p;
            while (x % p == 0)
                x /= p;
        }
    }
    if (x > 1)
        ans -= ans / x;
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int sq = sqrt(n) + 1;
    if (k >= sq) {
        cout << 1 % MOD << endl;
        return;
    }
    k = (k + 1) / 2;
    while (k-- && n > 1)
        n = phi(n);
    cout << n % MOD << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
