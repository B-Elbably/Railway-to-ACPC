#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n, m, a, b;
void brute(int ok) {
    if (ok) swap(a, b);
    int steps = n * m * 2;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    int i = 0, j = 0;
    while (steps--) {
        grid[i][j] = 1;
        if (steps & 1) i += a;
        else j += b;
        i %= n; j %= m;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (!grid[i][j]) {
                cout << i + 1 << " " << j + 1 << "\n";
                // cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

void solve() {
    cin >> n >> m >> a >> b;
    // if (a == b && a == 1) {
    //     cout << "YES\n";
    //     return;
    // }
    int g1 = gcd(a, n);
    int g2 = gcd(m , b);
    int g3 = gcd(n, m);
    if (g1 == g2 && g1 == 1 && g3 <= 2) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    // cout << g1 << " " << g2  << " " << g3 << "\n";
    // if (gcd(a, n) == 1 && gcd(b, m) == 1) {
    //     // if ((n % 2 == 0) && (m % 2 == 0)) {
    //         // cout << "NO\n";
    //     // }else {
    //     if (gcd(n, m) == 2)
    //         cout << "YES\n";
    //     else 
    //         cout << "NO\n";
    //     // }
    //     return;
    //     // return;
    // }
    // if (gcd(n ,a) != 1 || gcd(m, b) != 1 || gcd(n, m) != 1){
        // cout << "NO\n";
    // }else {
        // cout << "NO\n";
    // }
    // if ()
    // if ((n % a == 0) || (b % m == 0)) {
    //     cout << "NO\n";
    // }else {
    //     cout << "YES\n";
    // }



    // brute(1);
    // brute(0);
    // for (int i = 1; i <= a; ++i) {
    //     // cout << n << " " << i << " ";
    //     // cout << gcd(n, i) << " ";
    //     brute2(n, i);
    // }
    // cout << "=========\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
