#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 2e5 + 5;
int memo[3][21][N];
int n, k, x;
const int inf = -1e16;
vector<int> a;
int go(int i, int rem, int status) {
    if (rem < 0) return inf;
    if (i == n) return (rem == 0) ? 0 : inf;
    int &ret = memo[status][rem][i];
    if (~ret) return ret;
    ret = inf;

    if (status == 0) {
        ret = max(ret, go(i + 1, rem, 0));
        ret = max(ret, go(i + 1, rem - 1, 0));
        
        ret = max(ret, (a[i] - x) + go(i + 1, rem, 1));
        ret = max(ret, (a[i] + x) + go(i + 1, rem - 1, 1));
        
        ret = max(ret, go(i, rem, 2));
    }else if (status == 1) {
        ret = max(ret, (a[i] - x) + go(i + 1, rem, 1));
        ret = max(ret, (a[i] + x) + go(i + 1, rem - 1, 1));
        
        ret = max(ret, go(i, rem, 2));  
    }else {
        ret = max(ret, go(i + 1, rem, 2));
        ret = max(ret, go(i + 1, rem - 1, 2));
    }
    return ret;
}

void solve() {
    cin >> n >> k >> x;
    a.assign(n, 0);
    for (auto &i : a) cin >> i;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            memo[0][j][i] = -1;
            memo[1][j][i] = -1;
            memo[2][j][i] = -1;
        }
    }
    cout << go(0, k, 0) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
