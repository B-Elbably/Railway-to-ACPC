#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    while (n) {
        ans++;
        n/= 2;
    }
    int res = 1;
    while (res < ans) {
        res *= 2;
    }
    cout << res << " bit" << (res == 1 ? "" : "s") << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
