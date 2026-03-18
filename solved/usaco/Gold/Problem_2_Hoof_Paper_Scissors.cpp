#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e5 + 1;
vector<int> a(N);
int n, k;
int memo[3][21][N];

int go(int i, int used, int last) {
    if (i == n) return 0;
    int &ret = memo[last][used][i];
    if (~ret) return ret;
    int res = (last == a[i]) + go(i + 1, used, last);
    if (used < k) {
        int g2 = (last + 1) % 3;
        int g3 = (last + 2) % 3;
        res = max({res, 
                    (g2 == a[i]) + go(i + 1, used + 1, g2), 
                    (g3 == a[i]) + go(i + 1, used + 1, g3)});
    }

    return ret = res;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        if (c == 'H') a[i] = 0;
        else if (c == 'P') a[i] = 1;
        else a[i] = 2;
    }
    memset(memo, -1, sizeof(memo));
    int ans = 0;
    for (int last = 0; last < 3; last++) {
        ans = max(ans, go(0, 0, last));
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
