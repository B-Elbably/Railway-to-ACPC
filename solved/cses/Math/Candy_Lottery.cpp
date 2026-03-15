#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    double ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += i * (pow(i * 1.0 / m, n) - pow((i - 1) * 1.0 / m, n));
    }
    ans += 1e-15;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}


/*
    2 2         |  2 3 
                -   
    1 1 -> 1    |  1 1 -> 1
    1 2 -> 2    |  1 2 -> 2
    2 1 -> 2    |  1 3 -> 3
    2 2 -> 2    |  2 1 -> 2
                |  2 2 -> 2
                |  2 3 -> 3
                |  3 1 -> 3
                |  3 2 -> 3
                |  3 3 -> 3
                -
    1 -> 1      | 1 -> 1
    2 -> 3      | 2 -> 3
                | 3 -> 5
    7 / 4 =1.75 | 22 / 9 =2.44
*/

/*
    1 2         | 1 3
    map<max, freq>
    1 -> 1      | 1 -> 1
    2 -> 1      | 2 -> 1
                | 3 -> 1
                -
    3 / 2 = 1.5 | 6 / 3 = 2
*/

/*
    3 2        
    map<max, freq>
    1 -> 1
    2 -> 7
    15 / 8 = 1.875
*/

/*
    3 3 
    map<max, freq>
    1 -> 1
    2 -> 7
    3 -> 19
    72 / 27 = 2.66
*/
