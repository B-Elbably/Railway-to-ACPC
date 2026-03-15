#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MAXA = 1.5e7 + 5;
vector<int> spf(MAXA); 

void build() {
    for (int i = 2; i < MAXA; i++) spf[i] = i;
    for (int i = 2; i * i < MAXA; i++) {
        if (spf[i] == i) { // i is prime
            for (int j = i * i; j < MAXA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

vector<int> factorize(int x) {
    vector<int> primes;
    while (x > 1) {
        int p = spf[x];
        primes.push_back(p);
        while (x % p == 0) x /= p;
    }
    sort(all(primes));
    primes.erase(unique(all(primes)), primes.end());
    return primes;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int g = 0;
    for (auto x : a) g = gcd(g, x);
    for (auto &x : a) x /= g;
    map<int, int> freq;
    for (auto x : a) {
        if (x == 1) continue;
        vector<int> primes = factorize(x);
        for (auto p : primes) freq[p]++;
    }

    int ans = n;
    for (auto &[p, f] : freq) {
        ans = min(ans, n - f);
    }

    if (ans == n) ans = -1;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}