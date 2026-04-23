#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimize("O3,unroll-loops")
#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];  
    vector<vector<int>> prefix(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefix[i][j] = grid[i - 1][j - 1] 
                            + prefix[i - 1][j]
                            + prefix[i][j - 1] 
                            - prefix[i - 1][j - 1];
        }
    }
    vector<vector<int>> ans(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            for (int x = i; x < n; x++) {
                for (int y = j; y < m; y++) {
                    int sum = prefix[x + 1][y + 1] - prefix[i][y + 1] - prefix[x + 1][j] + prefix[i][j];
                    if (sum == k) {
                        ans[i][j]++;
                        ans[i][y + 1]--;
                        ans[x + 1][j]--;
                        ans[x + 1][y + 1]++;
                    }
                }
        }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            if (i > 0) ans[i][j] += ans[i - 1][j];
            if (j > 0) ans[i][j] += ans[i][j - 1];
            if (i > 0 && j > 0) ans[i][j] -= ans[i - 1][j - 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            if (ans[i][j] > 0) cout << grid[i][j] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
