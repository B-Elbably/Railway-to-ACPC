#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 20;
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


void solve() {
    string s; cin >> s;
    int n = s.size();
    int q; cin >> q;
    automaton(s);
    while (q--) {
        string t; cin >> t;
        int m = t.size();
        int ans;
        for (int i = 0; i < m; i++) {
            int last = pi[n + i - 1];
            int curi = t[i] - 'a';
            if (last < n){
                ans = aut[last][curi];
            }else {
                int j = last;
                while (j >= n && t[i] != t[j - n]) j = pi[j - 1];
                if (t[i] == t[j - n]) j++;
                if (j < n) ans = aut[j][curi];
                else ans = j;
            }
            cout << ans << " ";
            pi[n + i] = ans;
        }
        cout << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(pi, 0, sizeof(pi));
    memset(aut, -1, sizeof(aut));
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
