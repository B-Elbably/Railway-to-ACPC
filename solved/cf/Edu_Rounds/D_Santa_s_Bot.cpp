#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 998244353;
int fast_pow(int a, int b) {
    int res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        int m; cin >> m;
        a[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            freq[a[i][j]]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int m = a[i].size();
        for (int j = 0; j < m; ++j) {
            ans += freq[a[i][j]] * fast_pow((n * n) * m, MOD - 2) % MOD;
            ans %= MOD;
        }
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
