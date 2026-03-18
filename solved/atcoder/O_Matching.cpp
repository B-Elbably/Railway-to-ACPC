#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n;
vector<vector<int>> a;
const int MOD = 1e9 + 7;
const int N = 21;
int dp[N][1 << N];

int go(int i, int mask) {
    if (i == n) return 1;
    int &ret = dp[i][mask];
    if (~ret) return ret;
    ret = 0;
    for (int j = 0; j < n; j++) {
        if (!a[i][j]) continue;
        if (mask & (1 << j)) continue;
        ret += go(i + 1, mask | (1 << j));
        ret %= MOD;
    }
    return ret;
}

void solve() {
    cin >> n;
    a.resize(n, vector<int>(n));
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout << go(0, 0) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
