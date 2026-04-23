#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int mod = 1e9 + 7;
int fastpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> cnt;
    for (char c : s) cnt[c]++;
    int ans = 0;
    for (auto [k, v] : cnt) {
        ans += fastpow(2, v) - 1;
        ans %= mod;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
