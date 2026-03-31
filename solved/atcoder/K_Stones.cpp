#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int K = 1e5 + 5;
int n, k;
vector<int> a;

// int memo[K];
// int go(int rem) {
//     if (rem < a[0]) return 0;
//     int &ret = memo[rem];
//     if (~ret) return ret;
//     ret = 0;
//     for (int i = 0; i < n; ++i) {
//         if (rem >= a[i] && !go(rem - a[i])) {
//             return ret = 1;
//         }
//     }
//     return ret;
// }

int memo[K][2];
int go(int rem, int turn) {
    if (rem < a[0]) return 0; 
    int &ret = memo[rem][turn];
    if (~ret) return ret;
    for (int i = 0; i < n; ++i) {
        if (rem < a[i]) break;
        if (!go(rem - a[i], 1 ^ turn)) {
            return ret = 1;
        }
    }
    return ret = 0;
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    for (auto &x : a) cin >> x;
    memset(memo, -1, sizeof memo);
    sort(all(a));
    go(k, 0);
    cout << (memo[k][0] ? "First" : "Second") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
