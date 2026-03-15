#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    int ans = n * n;
    for (int i = 1; ;++i) {
        int j = i * i;
        if (j > n) break;
        ans -= (n - 1);
    }
    cout << ans << endl;
    // vector<vector<int>> a(n, vector<int>(n));
    // set<int> s;
    // for (int i = 0; i < n; i++) {
    //     a[0][i] = i + 1;
    //     s.insert(i + 1);
    // }
    // for (int j = 0; j < n; ++j) {
    //     int res = 0;
    //     for (int i = 0; i < n; ++i) {
    //         if (i == 0) {
    //             a[i][j] = j + 1;
    //         }else {
    //             a[i][j] = a[i - 1][j] * a[i - 1][j];
    //         }
    //         if (s.count(a[i][j])) continue;
    //         res += 1;
    //         s.insert(a[i][j]);
    //     }
    //     cout << j + 1 << " -> " << res << endl;
    // }
    
    // cout << s.size() << endl;


    // set<int> used;
    // int ans = n * n - (n - 1);
    // 3^1, 3^2, 3^3 ... ,   3^n
    //      9^1, ....,       9^(n / 2)
    //           27^1,      27^(n / 3)


    // cout << ans << endl;
    // for (int i = 0 ; i < n; ++i) {
    //     for (int j = 0; j < n;++j) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout <<  "========================" << endl;


    // int ans = 0;
    // 2^2 2^
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}


/*
1 2  3 4 
1 4  9 16
1 16 81 x
1 x  y  z
*/