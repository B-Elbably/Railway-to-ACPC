#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 2e2 + 15;
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

    aut[0][s[0] - 'A'] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            if (i < n && s[i] - 'A' == j) {
                aut[i][j] = i + 1;
            } else {
                aut[i][j] = aut[pi[i - 1]][j];
            }
        }
    }
}
string s1, s2, virus;
int dp[105][105][105];
int choice[105][105][105];
int n, m, v;
int go(int i, int j, int k) {
    if (k == v) return -1e9;
    if (i == n || j == m) return 0;
    int &ret = dp[i][j][k];
    if (~ret) return ret;
    ret = -1e9;
    int c = 0;
    int op1 = go(i + 1, j, k);
    if (op1 > ret) {
        ret = op1;
        c = 1;
    }
    int op2 = go(i, j + 1, k);
    if (op2 > ret) {
        ret = op2;
        c = 2;
    }
    if (s1[i] == s2[j]) {
        int nxt = aut[k][s1[i] - 'A'];
        int op3 = 1 + go(i + 1, j + 1, nxt);
        if (op3 > ret) {
            ret = op3;
            c = 3;
        }
    }
    choice[i][j][k] = c;
    return ret;
}

void solve() {
    cin >> s1 >> s2 >> virus;
    n = s1.size(); m = s2.size();
    v = virus.size();
    automaton(virus);
    memset(dp, -1, sizeof(dp));

    if (go(0, 0, 0) <= 0) {
        cout << 0 << endl;
        return;
    }

    string ans = "";
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (choice[i][j][k] == 3) {
            ans += s1[i];
            k = aut[k][s1[i] - 'A'];
            i++; j++;
        } else if (choice[i][j][k] == 1) {
            i++;
        } else if (choice[i][j][k] == 2) {
            j++;
        } else {
            break;
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