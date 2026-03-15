#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

/*  
    ab + ac + bc <= n; 
    c (b + a) + ab <= n;


    a + b + c <= x;
*/

void solve() {
    int n, x;
    cin >> n >> x;
    int ans = 0;
    for (int a = 1; a <= x - 2; ++a) {
        for (int b = 1; b <= x - a - 1; ++b) {
            int ab = a * b;
            if (ab >= n) break; 
            int c = (n - ab) / (a + b);
            c = min(c, x - a - b);
            c = max(c, 0LL);
            ans += c;
        }
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
