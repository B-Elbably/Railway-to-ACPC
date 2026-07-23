#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
int fast_pow(int base, int exp, int mod = MOD) {
    base %= mod;
    int res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
int freq[N + 1], cnt[N + 1], ans[N + 1];

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x, freq[x]++;
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            cnt[i] += freq[j];
        }
    }
    for (int i = N; i >= 1; --i) {
        ans[i] = fast_pow(2, cnt[i], MOD) - 1;
        ans[i] = (ans[i] + MOD) % MOD;  
        for (int j = i * 2; j < N; j += i) {
            ans[i] -= ans[j];
            if (ans[i] < 0) ans[i] += MOD;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
