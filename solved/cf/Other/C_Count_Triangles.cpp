#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    
    for (int i = a + b; i <= b + c; ++i) {
        int xy = max(0LL, min(b, i - b) - max(a, i - c) + 1);
        int z = max(0LL, min(d, i - 1) - c + 1);
        ans += xy * z;
    }
    
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}