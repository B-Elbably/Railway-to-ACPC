#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 5e3 + 5;
int memo[N][N];
int n;
vector<int> a;
int go(int i, int j) {
    if (i == j) return a[i];
    int &ret = memo[i][j];
    if (~ret) return ret;
    ret = go(i, j - 1) ^ go(i + 1, j);
    return ret;
}

int ans[N][N];
void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i], ans[i][i] = a[i];
    int q; cin >> q;
    memset(memo, -1, sizeof memo);
    go(0, n - 1);
    for (int j = 1; j < n; j++) {
        for (int i = 0; i + j < n; i++) {
            int jx = i + j;
            ans[i][jx] = go(i, jx);
            ans[i][jx] = max(ans[i][jx], ans[i][jx - 1]);
            ans[i][jx] = max(ans[i][jx], ans[i + 1][jx]);
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << ans[l - 1][r - 1] << endl;
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
