#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int calc(int n) {
    if (n == 0) return 0;
    if (n & 1) return 2 * calc(n / 2) + (n + 1) / 2;
    return calc(n - 1) + __builtin_popcountll(n);
}
void solve() {
    int n;
    cin >> n;
    // int sum = 0;
    // n++;
    // for (int i = 1; i <= n; i <<= 1) {
    //     sum += (n / (i * 2)) * i;
    //     sum += max(0LL, n % (i * 2) - i);
    // }
    // cout << sum << endl;
    
    cout << calc(n);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
