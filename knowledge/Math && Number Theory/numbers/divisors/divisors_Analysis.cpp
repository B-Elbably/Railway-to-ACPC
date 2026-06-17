#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n'
const int M = 1e9 + 7;
 
int exp(int base, int exp) {
    int res = 1; 
    base %= M;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % M;
        base = (base * base) % M; 
        exp /= 2;
    }
    return res;
}
 
void solve() {
    int n;
    cin >> n;
    
    int cnt = 1;
    int sum = 1;
    int mul = 1;
    int cnt_m1 = 1;
 
    for (int i = 0; i < n; i++) {
        int p, e;
        cin >> p >> e;
 
        // count of divisors = (e1 + 1) * (e2 + 1) * ... * (ek + 1)
        cnt = (cnt * (e + 1)) % M;
 
        // sum of divisors = ((p^(e+1) - 1) / (p - 1)) * ... for all prime factors
        int term = (exp(p, e + 1) - 1 + M) % M;
        term = (term * exp(p - 1, M - 2)) % M; 
        sum = (sum * term) % M;
 
        // product of divisors = p^(e*(e+1)/2) * ... for all prime factors
        int p_pow = (e * (e + 1) / 2) % (M - 1);
        p_pow = (p_pow * cnt_m1) % (M - 1);
        
        mul = (exp(mul, e + 1) * exp(p, p_pow)) % M;
        
        cnt_m1 = (cnt_m1 * (e + 1)) % (M - 1);
    }
 
    cout << cnt << " " << sum << " " << mul << endl;
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}