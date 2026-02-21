#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int f(int n) {
    for (int i = 2; i <= n + 1; i++) {
        if (n % i != 0) return i;
    }
}
int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}
const int MOD = 1e9 + 7;
void solve() {
    // int n;
    // for (int i = )
    // map<int, vector<int>> mp;
    // for (int i = 1; i <= N; i++) {
    //     // cout << i << " " << f(i) << "\n";
    //     mp[f(i)].push_back(i);
    // }
    // for (auto &[k, v] : mp) {
    //     if (k == 2) continue;
    //     cout << k << ": ";
    //     // cout << v.size() ;
    //     for (auto x : v) cout << x << " ";
    //     cout << "\n\n";
    // }
    int n;
    cin >> n;
    int ans = n, lc = 1;
    int add = LLONG_MAX;
    for (int i = 1; add; ++i){
        lc = lcm(lc, i);
        add = n / lc;
        ans += add; ans %= MOD;
    }
    cout << ans << endl;
} 

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
