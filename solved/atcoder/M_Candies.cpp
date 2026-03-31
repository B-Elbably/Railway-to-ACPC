#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int MOD = 1e9 + 7;
const int K = 1e5 + 5;
const int N = 105;
int k, n;
vector<int> a;
int memo[N][K];

int go(int i, int rem) {
    if (rem < 0) return 0;
    if (i == n) return rem == 0;
    int &ret = memo[i][rem];
    if (~ret) return ret;
    ret = 0;
    // for (int j = 0; j <= min(rem, a[i]); j++) {
    //     if (rem < j) break;
    //     ret += go(i + 1, rem - j);
    //     ret %= MOD;
    // }
    
    ret += go(i, rem - 1) + go(i + 1, rem);
    ret -= go(i + 1, rem - a[i] - 1);
    ret = (ret % MOD + MOD) % MOD;
    return ret;
}

void solve() {
    memset(memo, -1, sizeof(memo));
    cin >> n >> k;
    a.resize(n);
    for (auto &x : a) cin >> x;
    
    cout << go(0, k) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
