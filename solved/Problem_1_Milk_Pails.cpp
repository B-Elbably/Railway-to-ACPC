#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    for (int i = 0;;++i){
        for (int j = 0;;++j){
            int curr = i * a + j * b;
            if (curr > c) break;
            ans = max(ans, curr);
        }
        if (i * a > c) break;
    }

    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
