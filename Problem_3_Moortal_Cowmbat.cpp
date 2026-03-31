#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e15;
int n, m, K, dist[30][30], pref[100005][30], memo[100005][30], ans[100005];
string s;

int dp(int i, int c);

int go(int i) {
    if (i == 0) return 0;
    if (i < K) return INF;
    int &ret = ans[i];
    if (ret != -1) return ret;
    
    ret = INF;
    for (int c = 0; c < m; c++) {
        ret = min(ret, dp(i, c));
    }
    return ret;
}

int dp(int i, int c) {
    if (i < K) return INF;
    int &ret = memo[i][c];
    if (ret != -1) return ret;

    int res = dp(i - 1, c);
    if (res != INF) res += dist[s[i - 1] - 'a'][c];
    
    int op2 = go(i - K);
    if (op2 != INF) {
        res = min(res, op2 + (pref[i][c] - pref[i - K][c]));
    }

    return ret = res;
}

void solve() {
    cin >> n >> m >> K >> s;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> dist[i][j];

    for (int k = 0; k < m; k++)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int j = 0; j < m; j++) {
        pref[0][j] = 0;
        for (int i = 0; i < n; i++) {
            pref[i + 1][j] = pref[i][j] + dist[s[i] - 'a'][j];
        }
    }

    memset(memo, -1, sizeof(memo));
    memset(ans, -1, sizeof(ans));

    cout << go(n) << endl;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // freopen("cowmbat.in", "r", stdin);
    // freopen("cowmbat.out", "w", stdout);
    solve();
}