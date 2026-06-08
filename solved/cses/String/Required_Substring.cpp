#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int N = 1e6 + 15;
int pi[N];
void KMP(const string &s) {
    int n = s.size();
    for (int i = 0; i < n; i++) pi[i] = 0;
    
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
}

int aut[N][26];
void automaton(const string &s) {
    int n = s.size();
    KMP(s);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 26; j++) aut[i][j] = 0;
    }

    aut[0][s[0] - 'a'] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            if (i < n && s[i] - 'a' == j) {
                aut[i][j] = i + 1;
            } else {
                aut[i][j] = aut[pi[i - 1]][j];
            }
        }
    }
}
int dp[1005][105];
void solve() {
    int n;
    string s;
    cin >> n >> s;
    for (auto &c : s) c = tolower(c);
    int m = s.size();
    automaton(s);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int state = 0; state < m; state++) {
            for (int c = 0; c < 26; c++) {
                int nxt = aut[state][c];
                if (nxt == m) continue;
                dp[i + 1][nxt] += dp[i][state];
                dp[i + 1][nxt] %= MOD;
            }
        }
    }
    int bad = 0;
    for (int state = 0; state < m; state++) {
        bad += dp[n][state];
        bad %= MOD;
    }
    int total = 1;
    for (int i = 0; i < n; i++) {
        total = (total * 26) % MOD;
    }
    int ans = (total - bad + MOD) % MOD;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--)
        solve();

    return 0;
}