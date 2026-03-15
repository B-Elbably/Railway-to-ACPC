#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int mod = 1e9 + 7;
int fast_pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < 30; i++) {
        if (k & 1) ans = (ans + fast_pow(n, i)) % mod;
        k >>= 1;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
