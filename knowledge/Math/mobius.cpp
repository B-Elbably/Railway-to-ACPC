#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

// -1 -> odd no. of prime factors
//  0 -> ! square free
//  1 -> even no. of prime factors 

/*
    NOTE: Important for :
        -> Inclusion-exclusion principle

*/

// int mobius(int n) {
//     int res = 1;
//     for (int i = 2; i * i <= n; i++) {
//         if (n % i == 0) {
//             n /= i;
//             res *= -1;
//             if (n % i == 0) return 0;
//         }
//     }
//     if (n > 1) res *= -1;
//     return res;
// }

const int MAX = 1e6;
vector<int> mobius(MAX + 1);
vector<bool> prime(MAX + 1);
vector<int> pref_mobius(MAX + 1);

void build_mobius() {
    for (int i = 0; i <= MAX; i++) {
        mobius[i] = 1;
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    for (int i = 2; i <= MAX; i++) {
        if (prime[i]) {
            int step = i;
            for (int j = i; j <= MAX; j += step) {
                prime[j] = false;
                mobius[j] *= -1;
            }
            step *= i;
            for (int j = i * i; j <= MAX; j += step) {
                mobius[j] = 0;
            }
        }
    }
    pref_mobius[0] = 0;
    for (int i = 1; i <= MAX; i++) {
        pref_mobius[i] = pref_mobius[i - 1] + mobius[i];
    }
}



int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

// Number of pairs with size = k; its gcd = 1; <= n;
int count_pairs(int n, int k) { // O(sqrt(n))
    int ans = 0;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        int val = n / l;
        ans += (pref_mobius[r] - pref_mobius[l - 1]) * binpow(val, k);
    }
    return ans;
}

// Same but O(n)
int count_pairs(int n, int k) {
    int ans = 0;
    for (int d = 1; d <= n; d++) {
        ans +=  mobius[d] * binpow(n / d, k);
    }
    return ans; 
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
