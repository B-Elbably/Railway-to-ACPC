#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m; 
    cin >> n >> m;
    // int one = (n / 2) + (n % 2);
    // int total = one;
    // cout << total << endl;
    int kk = min(16LL, 2* m);
    cout << ((n * m + kk - 1) / kk);
} 

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
