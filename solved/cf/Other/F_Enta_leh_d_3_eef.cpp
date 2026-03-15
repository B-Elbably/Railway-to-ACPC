#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

void solve() {
    int a, k;
    cin >> a >> k;
    // k / gcd(a,b) == 1 + (a * b)
    int g = k % a;
    if (g == 0) g = a;
    int b = ((k - g) * g) / a;
    if (gcd(a, b) + lcm(a, b) != k) {
        b = -1;
    }
    cout << b << endl;
    // // if (k <= a) {
    // //     cout << -1 << endl;
    // //     return;
    // // }
    // // if (a == 1 || (k - a) == 1) {
    // //     cout << k - a << endl;
    // //     return;
    // // }
    // // k > a; k > b;
    // map<int, vector<pair<int, int>>> mp; 
    // for (int i = 2; i <= a; ++i) {
    //     for (int j = i; j <= a; ++j) {
    //         // cout << i << ' ' << j << ' ';
    //         int K = gcd(i, j) + lcm(i, j);
    //         mp[K].push_back({i, j});
    //     }
    // }
    // for (auto& [K, v] : mp) {
    //     // if ((K & 1) == 0)  continue;   
    //     // if (v.size() > 1)  continue;
    //     cout << K << ": ";
    //     for (auto& x : v) {
    //         // if (x.first + x.second == K) {
    //         //     continue;
    //         // }
    //         cout << '(' << x.first << ',' << x.second << ") ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}


/*

gcd(a, b) + gcd(a, b) * A * B == k
gcd(6, b) + gcd(6, b) * 6 * b == k

*/