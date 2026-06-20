#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int modpow(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = (__int128)res * a % mod;
        a = (__int128)a * a % mod;
        b >>= 1;
    }
    return res;
}

// Requires gcd(a, m) = 1 
int BSGS(int a, int b, int m) {
    a %= m;
    b %= m;
    if (b == 1)
        return 0;
    int n = sqrtl(m) + 1;
    unordered_map<int, int> mp;
    mp.reserve(n * 2);
    int cur = b;
    for (int q = 0; q < n; q++) {
        if (!mp.count(cur))
            mp[cur] = q;
        cur = (__int128)cur * a % m;
    }
    int an = modpow(a, n, m);
    cur = 1;
    for (int p = 1; p <= n + 1; p++) {
        cur = (__int128)cur * an % m;
        if (mp.count(cur))
            return p * n - mp[cur];
    }
    return -1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
