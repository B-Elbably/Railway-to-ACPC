#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n, m;
const int N = 1005;
int a[N], b[N];
int memo[N][N]; 
int choice[N][N];
int solve(int i, int j) {
    if (i == n || j == m) return 0;
    int &ret = memo[i][j];
    if (~ret) return ret;
    if (a[i] == b[j]) {
        ret = 1 + solve(i + 1, j + 1);
        choice[i][j] = 1;
    } else {
        int op1 = solve(i + 1, j);
        int op2 = solve(i, j + 1);
        if (op1 >= op2) {
            ret = op1;
            choice[i][j] = 2;
        } else {
            ret = op2;
            choice[i][j] = 3;
        }
    }
    return ret;
}

void trace(int i, int j) {
    if (i == n || j == m) return;
    if (choice[i][j] == 1) {
        cout << a[i] << " ";
        trace(i + 1, j + 1);
    } else if (choice[i][j] == 2) {
        trace(i + 1, j);
    } else {
        trace(i, j + 1);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    
    memset(memo, -1, sizeof(memo));
    cout << solve(0, 0) << endl;
    trace(0, 0);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}