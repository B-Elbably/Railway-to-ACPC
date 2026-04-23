#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 51;
const int W = 25e3 + 1;

int n, w;
int memo[2][N][W];

vector<int> a;
int go(int i, int sum, int ok) {
    if (sum > w || ok > 1) return 0;
    if (i == n) {
        return (ok == 1) && (sum == w);
    }
    int &ret = memo[ok][i][sum];
    if (~ret) return ret;
    ret = 0;
    ret |= go(i + 1, sum, ok);
    int ok2 = ok + (a[i] % 2 == 0);
    ret |= go(i + 1, sum + a[i], ok2);
    return ret;
}

void solve() {
    cin >> n >> w;
    a.resize(n);
    for (auto &x : a) cin >> x;
    memset(memo, -1, sizeof memo);
    cout << (go(0, 0, 0)? "YES": "NO");
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
