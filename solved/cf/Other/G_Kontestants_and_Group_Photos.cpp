#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
int memo[5005][5005];
vector<int> a;

int calc(int idx, int sum) {
    if (sum < 0) return 0;
    if (idx < 0) return sum == 0;
    int &ret = memo[idx][sum];
    if (~ret) return ret;
    int op1 = calc(idx - 1, sum) % MOD;
    int op2 = calc(idx - 1, sum - a[idx]) % MOD;
    return ret = (op1 + op2) % MOD;
}

void solve() {
    int n;
    cin >> n;
    a.resize(n);
    for (auto &x : a) cin >> x;
    sort(all(a));
    memset(memo, -1, sizeof(memo));
    int add = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int bad = 0;
        for (int s = 0; s <= a[i]; s++) {
            bad = (bad + calc(i - 1, s)) % MOD;
        }
        ans = (ans + add - bad + MOD) % MOD;
        add = (add * 2) % MOD;
    }
    
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("polygon.in", "r", stdin);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
