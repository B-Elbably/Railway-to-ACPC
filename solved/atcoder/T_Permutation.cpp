#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 3005;
const int MOD = 1e9 + 7;
int memo[N][N];
string s;
int n;

int go(int i, int j) {
    if (j <= 0) return 0;
    if (i == 1) return 1;
    int &ret = memo[i][j];
    if (~ret) return ret;
    ret = 0;
    if (s[i - 2] == '<') {
        ret = go(i - 1, j - 1);
    } else {
        ret = (go(i - 1, i - 1) - go(i - 1, j - 1) + MOD) % MOD;
    }
    ret += go(i, j - 1); ret %= MOD;
    return ret;
}

void solve() {
    cin >> n >> s;
    memset(memo, -1, sizeof memo);
    cout << go(n, n) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}