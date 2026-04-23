#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n;
vector<int> a, b;
int memo[1005][1005];

int go(int i, int j) {
    if (i == n || j == n) return 0;

    int &ret = memo[i][j];
    if (~ret) return ret;
    ret = go(i + 1, j);
    ret = max(ret, go(i, j + 1));
    if (abs(a[i] - b[j]) <= 4) {
        ret = max(ret, 1 + go(i + 1, j + 1));
    }

    return ret;
}

void solve() {
    cin >> n;
    a.resize(n); b.resize(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    memset(memo, -1, sizeof(memo));
    cout << go(0, 0) << endl;
}

int32_t main() {        
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
