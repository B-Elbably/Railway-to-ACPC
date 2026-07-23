#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
vector<string> a;
const int N = 2e3 + 5;
int up[N][N];
int ri[N][N];
int vis[N][N];
int n, m;


void solve() {
    cin >> n >> m;
    a.resize(n);
    int ans = 0;
    for (auto &x : a) cin >> x;
    queue<pair<int, int>> q;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (j + 1 < m && a[i][j] == a[i][j + 1]) {
                ri[i][j] = ri[i][j + 1] + 1;
            } else {
                ri[i][j] = 0;
            }
        }
    }
    for (int j = m - 1; j >= 0; --j) {
        for (int i = 0; i < n; ++i) {
            if (i - 1 >= 0 && a[i][j] == a[i - 1][j]) {
                up[i][j] = up[i - 1][j] + 1;
            } else {
                up[i][j] = 0;
            }
        }
    }
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << up[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << ri[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // if (i)
            ans += up[i][j] * ri[i][j];
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
