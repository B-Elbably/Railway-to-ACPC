#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int n, m;
int a[505], b[505];
int memo[505][505]; 
int choice[505][505];

int solve(int i, int last) {
    if (i == n) return 0;
    int &ret = memo[i][last + 1];
    if (~ret) return ret;
    ret = solve(i + 1, last);
    choice[i][last + 1] = -2; 
    for (int j = last + 1; j < m; j++) {
        if (a[i] == b[j]) {
            if (~last && b[j] <= b[last]) continue;
            int op = 1 + solve(i + 1, j);
            if (op > ret) {
                ret = op;
                choice[i][last + 1] = j;
            }
        }
    }
    return ret;
}

void trace(int i, int last) {
    if (i == n) return;
    int u = choice[i][last + 1];
    if (u >= 0) {
        cout << b[u] << " ";
        trace(i + 1, u);
    } else {
        trace(i + 1, last);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> b[i];
    memset(memo, -1, sizeof(memo));

    cout << solve(0, -1) << endl;
    trace(0, -1);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
