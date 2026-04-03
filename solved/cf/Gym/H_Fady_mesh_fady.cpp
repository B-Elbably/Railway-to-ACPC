#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int lcm__(int a, int b) {
    return (a / __gcd(a, b)) * b;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)cin >> x;
    int lc = a[0];
    for (int i = 1; i < n; ++i) lc = lcm__(lc, a[i]);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += lc / a[i];
    }
    cout << ans << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
