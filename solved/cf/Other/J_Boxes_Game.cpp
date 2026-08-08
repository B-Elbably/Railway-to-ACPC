#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n;
vector<int> a;
const int N = 1e3 + 5;
int dp[N][N];

int go(int i, int j) {
    if (i > j) return 0;
    int &ret = dp[i][j];
    if (~ret) return ret;
    int turn = (n - (j - i + 1)) % 2;
    if (turn == 0) {
        int op1 = a[i] + go(i + 1, j);
        int op2 = a[j] + go(i, j - 1);
        ret = max(op1, op2);
    } else {
        int op1 = - a[i] + go(i + 1, j);
        int op2 = - a[j] + go(i, j - 1);
        ret = min(op1, op2);
    }
    return ret;
}

void solve() {
    cin >> n;
    a.resize(n);
    for (auto &x : a) cin >> x;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = -1;
    cout << go(0, n - 1) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
