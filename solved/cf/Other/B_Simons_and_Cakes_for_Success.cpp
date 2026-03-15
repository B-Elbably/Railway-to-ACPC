#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

// int fast_pow(int a, int b, int mod) {
//     int res = 1;
//     a %= mod;
//     while (b > 0) {
//         if (b & 1) res = (res * a) % mod;
//         a = (a * a) % mod;
//         b >>= 1;
//     }
//     return res;
// }

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

set<int> divs(int n) {
    set<int> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.insert(i);
            res.insert(n / i);
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    set<int> d = divs(n);
    vector<int> ans;
    // for (auto &x : ans) cout << x << " ";
    // cout << d.size() << endl;
    for (auto &x : d) {
        if (is_prime(x)) ans.push_back(x);
    }
    int res = 1;
    for (int x: ans) res *= x;
    cout << res << endl;
    // for (int n = 1; n <= 100; n++) {
    //     if (is_prime(n)) continue;
    //     for (int k = 2; ;k++){
    //         if (fast_pow(k,n, 1e18 + 7) % n == 0) {
    //             cout << n << " " << k << endl;
    //             break;
    //         }
    //     }
    // }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
