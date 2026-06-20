#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int MOD = 1000000000000000031LL;
const int G = 42;

int fast_pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = (__int128)res * a % MOD;
        a = (__int128)a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    int x = 300;
    for (int i = 0; i < 1000000 - n; i++) {
        x = fast_pow(G, x);
    }
    cout << x << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
