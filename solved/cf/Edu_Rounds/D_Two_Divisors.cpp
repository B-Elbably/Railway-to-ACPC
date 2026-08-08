#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

// vector<int> factorize(int x) {
//     vector<int> res;
//     for (int i = 2; i * i <= x; i++) {
//         if (x % i == 0) {
//             res.push_back(i);
//             if (i != x / i) res.push_back(x / i);
//         }
//     }
//     if (x > 1) res.push_back(x);
//     return res;
// }
// const int N = 5e5 + 5;
// int ans[2][N];

// bool isprime(int n) {
//     if (n <= 1) return false;
//     for (int i = 2; i * i <= n; i++) {
//         if (n % i == 0) return false;
//     }
//     return true;
// }

// bool ispowerof2(int n) {
//     return (n & (n - 1)) == 0;
// }

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n + 1);
//     // for (auto &x : a) cin >> x;
//     iota(all(a), 1);
//     for (int i = 0; i < n; i++) {
//         auto f = factorize(a[i]);
//         ans[0][i] = ans[1][i] = -1;
//         // if (ispowerof2(a[i])) continue;
//         // if (isprime(a[i])) continue;
//         for (auto x : f) {
//             if (~ans[0][i]) break;
//             for (auto y : f) {
//                 if (x == y) continue;
//                 if (gcd(a[i], x + y) == 1) {
//                     ans[0][i] = x;
//                     ans[1][i] = y;
//                     break;
//                 }
//             }
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         // if (ispowerof2(a[i])) continue;
//         // if (isprime(a[i])) continue;
//         if (ans[0][i] != -1) {
//             vector<int> f = factorize(a[i]);
//             sort(all(f));
//             int cnt = 0;
//             for (auto x : f) {
//                 if (!isprime(x)) continue;
//                 cnt++;
//             }
//             if (cnt == 2) continue;
//             cout << a[i] << "-> ";
//             for (auto x : f) {
//                 if (!isprime(x)) continue;
//                 cout << x << " ";
//             }
//             cout << " -> ";
//             for (int x: f) {
//                 if (!isprime(x)) continue;
//                 for (int y : f) {
//                     if (x >= y) continue;
//                     if (!isprime(y)) continue;
//                     if (gcd(a[i], x + y) == 1) {
//                         cout << "[" << x << " " << y << "] ";
//                         break;
//                     }
//                 }
//             }
//             // cout << "-> " << ans[0][i] << " " << ans[1][i];
//             cout << endl;
//         } 
//         // cout << a[i] << "-> " << ans[0][i] << " " << ans[1][i] << endl;
//     }
//     // for (int i = 0; i < n; i++) {
//     //     cout << ans[0][i] << " ";
//     // }
//     // cout << endl;
//     // for (int i = 0; i < n; i++) {
//     //     cout << ans[1][i] << " "; 
//     // }
// }

const int N = 1e7 + 1;
vector<int> primes;
int spf[N + 1];
void sieve() {
    for (int i = 2; i <= N; i++) {
        if (!spf[i]) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > spf[i] || 1LL * p * i > N) break;
            spf[p * i] = p;
        }
    }
}

const int M = 5e5 + 5;
int ans[2][M];
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        ans[0][i] = ans[1][i] = -1;
        int p = spf[x];
        int pw = 1;
        while (x % p == 0) {
            pw *= p;
            x /= p;
        }
        if (x != 1) {
            ans[0][i] = pw;
            ans[1][i] = x;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[0][i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[1][i] << " ";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
