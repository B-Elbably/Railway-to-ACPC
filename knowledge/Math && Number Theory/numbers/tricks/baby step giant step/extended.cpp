#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int modpow(int a, int b, int mod) {
    int res = 1;
    a %= mod;
    while (b) {
        if (b & 1)
            res = (__int128)res * a % mod;
        a = (__int128)a * a % mod;
        b >>= 1;
    }
    return res;
}
// gcd(a, m) >= 1
// O(sqrt(m) + log^2(m))
int extBSGS(int a, int b, int m) {
    a %= m;
    b %= m;
    if (b == 1 || m == 1) return 0;

    int g = __gcd(a, m);
    int count = 0;
    int na = 1;

    while (g > 1) {
        if (b % g != 0) {
            if (b == na) return count;
            return -1;
        }
        b /= g;
        m /= g;
        na = (__int128)na * (a / g) % m;
        count++;
        if (b == na) return count;
        g = __gcd(a, m);
    }

    int n = sqrtl(m) + 1;
    unordered_map<int, int> mp;
    mp.reserve(n * 2);
    
    int cur = b;
    for (int q = 0; q < n; q++) {
        mp[cur] = q;
        cur = (__int128)cur * a % m;
    }

    int an = modpow(a, n, m);
    cur = na;
    for (int p = 1; p <= n + 1; p++) {
        cur = (__int128)cur * an % m;
        if (mp.count(cur)) {
            return p * n - mp[cur] + count;
        }
    }
    return -1;
}

bool solve() {
    int x, z, k;
    if (!(cin >> x >> z >> k) || (!x && !z && !k)) return false;
    
    int ans = extBSGS(x, k, z);
    if (ans == -1) {
        cout << "No Solution" << endl;
    } else {
        cout << ans << endl;
    }
    return true;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (solve());
    return 0;
}