#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    double a, b, c;
    cin >> a >> b >> c;
    const double PI = acos(-1);    
    int A = round(asin(a) * 180.0 / PI);
    int B = round(asin(b) * 180.0 / PI);
    int C = round(asin(c) * 180.0 / PI);
    int ans = 0;
    ans = max(ans, A);
    ans = max(ans, B);
    ans = max(ans, C);
    if (A + B + C == 180) 
        cout << ans << endl;
    else 
        cout << 180 - ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
