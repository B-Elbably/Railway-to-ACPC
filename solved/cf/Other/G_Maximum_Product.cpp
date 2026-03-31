#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
string a, b;
int memo[20][2][2][2]; 
int choice[20][2][2][2];

int go(int i, int lo, int hi, int zero) {
    if (i == b.size()) return 1;
    int &ret = memo[i][lo][hi][zero];
    if (~ret) return ret;
    ret = -1;
    int mn = lo ? a[i] - '0' : 0;
    int mx = hi ? b[i] - '0' : 9;
    for (int j = mn; j <= mx; ++j) {
        int z = zero && (j == 0);
        int l = lo && (j == mn);
        int r = hi && (j == mx);
        int sum = go(i + 1, l, r, z);
        int val = sum * (z ? 1 : j);
        if (val > ret) {
            ret = val;
            choice[i][lo][hi][zero] = j;
        }
    }
    return ret;
}

void solve() {
    cin >> a >> b;
    int n = b.size();
    a = string(n - a.size(), '0') + a;
    memset(memo, -1, sizeof memo);
    go(0, 1, 1, 1);

    int lo = 1, hi = 1, z = 1;
    for (int i = 0; i < n; i++) {
        int j = choice[i][lo][hi][z];
        lo &= (j == a[i] - '0');
        hi &= (j == b[i] - '0');
        if (!z || j > 0) {
            cout << j;
        }
        z &= (j == 0);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
