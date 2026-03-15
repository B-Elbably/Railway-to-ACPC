#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
int n;
string a;
vector<int> pref;
map<pair<int, int>, int> memo;

int go(int L, int R) {
    if (L > R) return 1;
    if (memo.count({L, R})) return memo[{L, R}];
    int &ret = memo[{L, R}];
    
    int rem = pref[R + 1] - pref[L];
    int ones = pref[n] - rem;
    int zero = (n - (R - L + 1)) - ones;
    ret = 0;

    // go
    zero += (a[L] == '0');
    ones += (a[L] == '1');
    if (ones >= zero) {
        ret = (ret + go(L + 1, R)) % MOD;
    }
    if (L >= R) return ret;
    zero -= (a[L] == '0');
    ones -= (a[L] == '1');


    zero += (a[R] == '0');
    ones += (a[R] == '1');
    // back
    if (ones >= zero) {
        ret = (ret + go(L, R - 1)) % MOD;
    }
    return ret;
}

void solve() {
    cin >> n;
    pref.assign(n + 1, 0);
    // string a;
    cin >> a;
    for (int i = 0; i < n; i++){
        pref[i + 1] = pref[i] + (a[i] == '1');
    }
    int ans = go(0, n - 1) + 1;
    cout << ans % MOD << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}