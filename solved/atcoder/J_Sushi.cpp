#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 301;
double memo[N][N][N];
int vis[N][N][N];
int n;

double go(int c1, int c2, int c3) {
    if (c1 == 0 && c2 == 0 && c3 == 0) return 0;
    double &ret = memo[c1][c2][c3];
    if (vis[c1][c2][c3]) return ret;
    vis[c1][c2][c3] = 1;
    ret = n;
    if (c1 > 0) ret += c1 * go(c1 - 1, c2, c3);
    if (c2 > 0) ret += c2 * go(c1 + 1, c2 - 1, c3);
    if (c3 > 0) ret += c3 * go(c1, c2 + 1, c3 - 1);
    ret /= (c1 + c2 + c3);
    return ret;
}

void solve() {
    cin >> n;
    vector<int> a(n);
    int c1 = 0, c2 = 0;
    for (auto &x : a) {cin >> x; c1 += (x == 1); c2 += (x == 2);}
    memset(memo, -1, sizeof memo);
    memset(vis, 0, sizeof vis);
    cout << go(c1, c2, n - c1 - c2) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
