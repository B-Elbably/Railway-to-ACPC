#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1002;
pair<int, int> a[N][N];
pair<int, int> dp[N][N];
bool vis[N][N];
int n;

pair<int, int> add(pair<int, int> x, pair<int, int> y) {
    return {x.first + y.first, x.second + y.second};
}

int val(pair<int, int> x) {
    return min(x.first, x.second);
}

pair<int, int> go(int i, int j) {
    if (i > n || j > n) return {1e18, 1e18};
    if (i == n && j == n) return a[i][j];
    if (vis[i][j]) return dp[i][j];
    vis[i][j] = true;
    auto op1 = go(i, j + 1);
    auto op2 = go(i + 1, j);
    return dp[i][j] = add(a[i][j], (val(op1) < val(op2) ? op1 : op2));
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            vis[i][j] = false;
            a[i][j] = {0, 0};
            int x;
            cin >> x;
            if (x == 0) {
                a[i][j] = {1, 1};
                continue;
            }
            while (x % 2 == 0) {
                a[i][j].first++;
                x /= 2;
            }
            while (x % 5 == 0) {
                a[i][j].second++;
                x /= 5;
            }
        }
    }
    
    auto ans = go(1, 1);
    cout << val(ans) << endl;
    int r = 1, c = 1;
    while (r < n || c < n) {
        if (r == n) {
            cout << 'R';
            c++;
        } else if (c == n) {
            cout << 'D';
            r++;
        } else {
            if (val(go(r + 1, c)) < val(go(r, c + 1))) {
                cout << 'D';
                r++;
            } else {
                cout << 'R';
                c++;
            }
        }
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}