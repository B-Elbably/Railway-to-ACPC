#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e4 + 5;
const int K = 1e3 + 5; 
int n, k;
vector<int> a;
int memo[N][K];

int go(int i, int len, int mx) {
    if (i == n) return len * mx;
    int &ret = memo[i][len];
    if (~ret) return ret;
    mx = max(mx, a[i]);
    ret = (len + 1) * mx + go(i + 1, 0, 0);
    if (len + 1 < k) {
        ret = max(ret, go(i + 1, len + 1, mx));
    }   
    return ret;
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    for (auto &x : a) cin >> x;
    memset(memo, -1, sizeof(memo));
    cout << go(0, 0, 0) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
