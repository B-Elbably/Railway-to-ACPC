#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
bool isprime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// int n = 0;
void solve() {
    int n;
    cin >> n;
    // n++;
    // for (int i = 2; i < n - 2; ++i) {
    //     if (gcd(i, n - i) > 1) {
    //         // if (isprime(i))
    //         cout << n << " " << i << " " << n - i << " YES\n";
    //         return;
    //     }
    // }
    // cout << n << " NO\n";
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            if (gcd(i, n - i) > 1) {
                cout << " YES\n";
                return;
            }
        }
    }
    cout << " NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
