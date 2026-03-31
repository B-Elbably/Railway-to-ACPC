#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    // if (k > n + n - 1) {
    //     cout << 0;
    //     return;
    // }
    cout << max(0LL,(k - 1) / 2 - max(0LL, k - 1 - n));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
