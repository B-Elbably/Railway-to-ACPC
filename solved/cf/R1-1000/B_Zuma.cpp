#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 505;
const int MOD = 1e9 + 7;
int memo[N][N];
vector<int> a;
int n;

// int go(int l, int r) {
//     if (l >= r) return l == r;
//     int &ret = memo[l][r];
//     if (~ret) return ret;
//     ret = 1 + go(l + 1, r);
//     if (a[l] == a[l + 1]) {
//         ret = min(ret, 1 + go(l + 2, r));
//     }
//     for (int i = l + 2; i <= r; i += 1) {
//         if (a[l] == a[i]) {
//             ret = min(ret, go(l + 1, i - 1) + go(i + 1, r));
//         }    
//     }
//     return ret;
// }
int go(int l, int r) {
    if (l > r) return 0;
    int &ret = memo[l][r];
    if (~ret) return ret;
    ret = 1e9;
    for (int i = l ; i <= r; i++) {
        if (a[l] == a[i]) {
            ret = min(ret, (i - l <= 1) + go(l + 1, i - 1) + go(i + 1, r));
        }
    }
    return ret;
}

void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(memo, -1, sizeof memo);
    cout << go(0, n - 1) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
