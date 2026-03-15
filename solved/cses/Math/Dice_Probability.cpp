#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

double dp[101][601];
void build() {
    dp[0][0] = 1.0;
    for (int i = 1; i <= 100; ++i){
        for (int j = i; j <= i * 6; j++){
            for (int k = 1; k <= 6; k++) {
                if (j < k) continue;
                dp[i][j] += dp[i - 1][j - k] / 6.0;
            }
        }
    }
}
void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    a = max(a, n);
    b = min(b, n * 6);
    double ans = 0;
    for (int i = a; i <= b; ++i) {
        ans += dp[n][i]; 
    }
    cout << fixed << setprecision(6) << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
