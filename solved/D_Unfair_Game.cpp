#include <bits/stdc++.h>
using namespace std;

int comb[31][31];
int dp[31][31];

void build() {
    for (int i = 0; i <= 30; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
        }
    }
    for (int i = 0; i <= 30; i++) {
        for (int j = i; j >= 0; j--) {
            dp[i][j] = comb[i][j] + dp[i][j+1];
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0, d = __builtin_ctzll(n); 
    for (int m = (k + 1) / 2; m < d; m++) {
        ans += dp[m][max(k - m, 0)];
    }
    ans += (1 + d) > k;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    build();
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}