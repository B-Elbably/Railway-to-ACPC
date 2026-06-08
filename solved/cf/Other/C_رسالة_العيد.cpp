#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 27;
vector<int> adj[N];
int dp[N][N];
const int inf = 1e9;
void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = inf;
        }
    }
    string s;
    string t;
    int n;
    cin >> s >> t >> n;
    if (s.size() != t.size()) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < n;i++) {
        char a, b;
        cin >> a >> b;
        int u = a - 'a';
        int v = b - 'a';
        int w;
        cin >> w;
        adj[u].push_back(v);
        dp[u][v] = min(dp[u][v], w);
    }
    for (int i = 0; i < 27; i++) {
        dp[i][i] = 0;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    
    int ans = 0;
    vector<char> res;
    n = s.size();
    for (int i = 0; i < n; i++) {
        int now = inf;
        char ch = 'a';
        for (int j = 0; j < 26; ++j) {
            int cur = dp[s[i] - 'a'][j] + dp[t[i] - 'a'][j];
            if (cur < now) {
                now = cur;
                ch = j + 'a';
            }
        }
        if (now >= inf) {
            cout << -1 << endl;
            return;
        }
        ans += now;
        res.push_back(ch);
    }
    cout << ans << endl;
    for (char c : res) {
        cout << c;
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
