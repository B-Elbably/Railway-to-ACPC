#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 1e5 + 5;
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
int n, m;
string s, t;
vector<vector<int>> memo;

int go(int i, int j) {
    if (i == n) return 0;
    int &ret = memo[i][j];
    if (~ret) return ret;
    int ans = 0;
    for (int c = 0; c < 26; ++c) {
        if (s[i] != '?' && s[i] - 'a' != c) continue;
        ans = max(ans, go(i + 1, aut[j][c]) + (aut[j][c] == m));
    }
    return ret = ans;
}

void solve() {
    cin >> s >> t;
    n = s.size(), m = t.size();
    automaton(t);
    int cur = 0, ans = 0;
    int n = s.size(), m = t.size();
    memo.assign(n + 1, vector<int>(m + 1, -1));
    cout << go(0, 0) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}