#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n;
vector<int> a;
vector<int> primes;
const int N = 19;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

const int MOD = 1e9 + 7;
int fastpow(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

void solve() {
    cin >> n;
    a.resize(n);
    for (auto &x : a) cin >> x;
    for (int i = 2; i < 70; i++) {
        if (isPrime(i)) primes.push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        int ai = 0;
        for (int j = 0; j < primes.size(); j++) {
            int cnt = 0;
            while (a[i] % primes[j] == 0) {
                a[i] /= primes[j];
                cnt++;
            }
            if (cnt % 2) ai |= (1LL << j);
        }
        a[i] = ai;
    }
    int sz = 1 << primes.size();
    vector<int> dp(sz, 0), ndp(sz, 0);
    dp[0] = 1;
    map<int, int> freq;
    for (int i : a) freq[i]++;
    for (auto [i, count] : freq) {
        int pw = fastpow(2, count - 1);
        for (int mask = 0; mask < sz; mask++) {
            ndp[mask] += dp[mask] * pw % MOD;
            ndp[mask ^ i] += dp[mask] * pw % MOD;
            ndp[mask] %= MOD; 
        }
        swap(dp, ndp);
        fill(all(ndp), 0);
    }
    cout << dp[0] - 1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
