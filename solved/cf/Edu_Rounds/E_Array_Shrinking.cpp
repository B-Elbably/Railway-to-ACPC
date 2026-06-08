#include <bits/stdc++.h>
using namespace std;

#define int int
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int n;
vector<int> a;
const int N = 505;
int memo[N][N];
int dp[N];

int range(int i, int j) {
    if (i == j) return a[i];
    int &ret = memo[i][j];
    if (ret != -2) return ret;
    for (int k = i; k < j; k++) {
        int left = range(i, k);
        int right = range(k + 1, j);
        if (left == -1) continue;
        if (right != left) continue;
        return ret = left + 1;
    }
    return ret = -1;
}

void solve() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            memo[i][j] = -2;
            
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 1; j <= i; j++) {
            if (~range(j, i)) {
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    cout << dp[n] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
