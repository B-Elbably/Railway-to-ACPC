#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n;
vector<int> a;
const int N = 5e3 + 5;
int dp[N][N];

int dfs(int i, int j) {
    if (i > j) return 0;
    int &ret = dp[i][j];
    if (~ret) return ret;
    ret = 0;
    int op1 = a[i] * (i + 1 + n - j - 1) + dfs(i + 1, j);
    int op2 = a[j] * (i + 1 + n - j - 1) + dfs(i, j - 1);
    return ret = max(op1, op2);
}

void solve() {
    cin >> n;
    a.resize(n);
    for (auto &x : a) cin >> x;
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, n - 1) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
