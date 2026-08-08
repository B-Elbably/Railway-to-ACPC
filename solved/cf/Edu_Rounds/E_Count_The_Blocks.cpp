#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int m = 998244353;

int fastpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

map<int, int> mp;

void solve() {
    int n;
    cin >> n;
    // int mx = 10;
    // for (int i = 2; i <= n; ++i) {
    //     mx *= 10;
    // }
    // for (int i = 0; i < mx; ++i) {
    //     string s = to_string(i);
    //     if (s.size() < n)
    //         s = string(n - s.size(), '0') + s;
    //     int cnt = 1;
    //     int ch = s[0];
    //     for (int j = 1; j < n; ++j) {
    //         if (s[j] == ch) cnt++;
    //         else {
    //             mp[cnt]++;
    //             cnt = 1;
    //             ch = s[j];
    //         }
    //     }
    //     mp[cnt]++;
    // }
    for (int i = 1; i < n; ++i) {
        mp[i] = fastpow(10, n - i - 1) *
            (180 + 81LL * (n - i - 1)) % m;
        cout << mp[i] << " ";
    }
    cout << 10 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
