#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int x, n;
    cin >> x >> n;
    int ans = x / n;
    int rem = x % n;
    ans -= gcd(rem, ans) == 1;
    cout << max(ans, 1LL) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
