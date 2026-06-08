#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
struct Matrix {
    int r, c;
};
int n;
vector<Matrix> a;
const int N = 101;
int dp[N][N];
int val[N][N];

int go(int i, int j) {
    if (i == j) return 0;
    int &ret = dp[i][j];
    if (~ret) return ret;
    ret = LLONG_MAX;
    for (int k = i; k < j; k++) {
        int left = go(i, k);
        int right = go(k + 1, j);
        if (left == LLONG_MAX) continue;
        if (right == LLONG_MAX) continue;
        int op = left + right + a[i].r * a[k].c * a[j].c;
        ret = min(ret, op);
    }
    return ret;
}

void solve() {
    cin >> n;
    a.resize(n);
    for (auto &x : a) cin >> x.r >> x.c;
    memset(dp, -1, sizeof(dp));
    cout << go(0, n - 1) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
