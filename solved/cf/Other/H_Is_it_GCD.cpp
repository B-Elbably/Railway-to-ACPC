#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    vector<int> freq(N, 0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {cin >> x; freq[x]++;}
    for (int i = 1; i < N; i++) {
        for (int j = 2 * i; j < N; j += i) {
            freq[i] += freq[j];
        }
    }
    vector<int> ans(N, 0);
    for (int i = N - 1; i >= 1; i--) {
        if (freq[i] == 0) continue;
        int res = (freq[i] * power(2, freq[i] - 1)) % MOD;
        for (int j = 2 * i; j < N; j += i) {
            res -= ans[j] - MOD;
            res %= MOD;
        }
        ans[i] = res;
        res += ans[i] * i;
        res %= MOD;
    }
    int res = 0;
    for (int i = 1; i < N; i++) {
        res += ans[i] * i;
        res %= MOD;
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
