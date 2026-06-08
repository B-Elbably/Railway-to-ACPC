#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 2e6 + 15;
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
    string s, t;
    cin >> s >> t;
    t += '#';
    s = t + s;
    KMP(s);
    int n = s.size();
    // cout <
    // for (int i = 0; i < n; i++) { 
    //     cout << pi[i] << ' ';
    // }
    int ans = 0;
    for (int i = t.size(); i < n; i++) {
        if (pi[i] == t.size() - 1) ans++;
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