#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());vector<int> primes;

const int N = 1e6 + 5;
int spf[N];

void build() {
    for (int i = 2; i < N; ++i) spf[i] = i;
    for (int i = 2; i < N; ++i) {
        if (spf[i] != i) continue;
        primes.push_back(i);
        for (int j = i * i; j < N; j += i) 
            if (spf[j] == j) spf[j] = i;
    }
}

set<int> candy;
void factorize(int x) {
    if (x <= 1) return;
    for (int p: primes) {
        if (p * p > x) break;
        if (x % p) continue;
        candy.insert(p);
        while (x % p == 0) x /= p;
    }
    if (x > 1) candy.insert(x);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    shuffle(all(a), mt);
    // shuffle(all(a), mt);
    int ans = LLONG_MAX;
    for (int i = 0; i < min(n, 20LL); ++i) {
        // candy.clear();
        for (int j = -2; j <= 2; ++j) {
            factorize(a[i] + j);
        }
    }
    for (int p: candy) {
        int cost = 0;
        for (int x: a) {
            if (x < p) {
                cost += p - x;
                continue;
            }
            int r = x % p;
            if (r == 0) continue;
            cost += min(r, p - r);            
        }
        ans = min(ans, cost);
    }
    if (ans == LLONG_MAX) ans = 0;
    cout << ans << endl;
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
