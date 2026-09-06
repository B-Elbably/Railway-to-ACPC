#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 20;
const int MOD = 1e9 + 7;
int freq[1 << N];

int fastpow(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x, freq[x]++;
    for (int bit = 0; bit < N; bit++) {
        for (int mask = 0; mask < (1 << N); mask++) {
            if (!(mask & (1 << bit))) {
                freq[mask] += freq[mask ^ (1 << bit)];
            }
        }
    }
    
    int ans = 0;
    for (int mask = 0; mask < (1 << N); ++mask) {
        int cnt = fastpow(2, freq[mask]);
        if (__builtin_popcount(mask) & 1)
            ans = (ans - cnt + MOD) % MOD;
        else
            ans = (ans + cnt) % MOD;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}