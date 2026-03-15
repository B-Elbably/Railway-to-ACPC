#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

/*
    phi(n) is no.of coprime <= n
    phi(p^k)= p^k - p^(k-1)
            = p^(k - 1) * (p - 1)
            = p^k * (1 - 1/p)
    phi(n^k) = n^(k - 1) * phi(n)

    NOTE: phi(x) is even for x > 2
    ! NOTE: sqrt(n) <= phi(n) <= n - sqrt(n) , n != [2, 6] 
*/

// Brute force approach
// int phi(int n) {
//     int res = 0;
//     for (int i = 1; i <= n; i++) {
//         if (__gcd(i, n) == 1) res++;
//     }
//     return res;
// }

// O(sqrt(n)) approach
int phi_(int n) {
    int res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            res -= res / i;
        }
    }
    if (n > 1) res -= res / n;
    return res;
}

// build phi table
int MAX = 1e6;
vector<int> phi(MAX + 1);
vector<bool> prime(MAX + 1);
void buildPhi() {
    for (int i = 0; i <= MAX; i++) {
        phi[i] = i;
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    for (int i = 2; i <= MAX; i++) {
        if (prime[i]) {
            for (int j = i; j <= MAX; j += i) {
                prime[j] = false;
                phi[j] -= phi[j] / i;
            }
        }
    }
}

int phi_factN(int n) {
    // phi(n!) = (N is prime? N - 1 : N) * phi((N - 1)!)
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= (prime[i] ? i - 1 : i);
    }
    return res;
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
}

