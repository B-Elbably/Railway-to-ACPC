#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
vector<int> a;
const int N = 4e2 + 5;
int memo[N][N];
int go (int l, int r) {
    if (l == r) return 0;
    int &ret = memo[l][r];
    if (~ret) return ret;
    ret = 1e18;
    for (int i = l; i < r; i++) {
        ret = min(ret, go(l, i) + go(i + 1, r) + a[r] - a[l - 1]);
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;
    a.resize(n + 1);
    memset(memo, -1, sizeof(memo));
    for (int i = 1; i <= n; i++) { cin >> a[i]; a[i] += a[i - 1]; }
    cout << go(1, n) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
