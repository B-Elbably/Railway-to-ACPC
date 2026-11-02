#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
vector<int> a;
const int MOD = 998244353;

int f(int lx , int rx) {
    int res = 0;
    for (int i = lx ; i <= rx; i++) res ^= a[i];
    return res % MOD;
}

void solve() {
    int n;
    cin >> n;
    a.resize(n);
    for (auto &x : a) cin >> x;
    int ans = 0;
    for (int i = 0; i < n; i++) { // O(n^3)
        int i_res = 0;
        for (int j = i; j < n; j++) {

            cout << "f(" << i << ", " << j << ") = " << f(i, j) << endl;
            ans += f(i, j) * (j - i + 1); 
            ans %= MOD;
            i_res += f(i, j) * (j - i + 1);
        }
        cout << "i = " << i << ", partial ans = " << i_res << endl;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
