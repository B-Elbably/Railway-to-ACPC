#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 5e3 + 5;
int memo[N][N];
int vis[N][N];
int n;
vector<int> a;
int go(int i, int j) {
    if (i > j) return 0;
    int &ret = memo[i][j];
    if (vis[i][j]) return ret;
    vis[i][j] = 1;
    int steps = n - (j - i + 1);
    if (steps % 2 == 0) {
        ret = max(a[i] + go(i + 1, j), a[j] + go(i, j - 1));
    } else {
        ret = min(go(i + 1, j), go(i, j - 1));
    }
    return ret;
}

void solve() {
    cin >> n;
    a.assign(n, 0);
    memset(memo, -1, sizeof(memo));
    for (auto &x : a) cin >> x;
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
