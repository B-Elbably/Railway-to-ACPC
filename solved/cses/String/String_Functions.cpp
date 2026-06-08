#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
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
int Z[N];
void z_function(const string& s) {
    int n = s.length();
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            Z[i] = min(r - i + 1, Z[i - l]);
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
            ++Z[i];
        if (i + Z[i] - 1 > r)
            l = i, r = i + Z[i] - 1;
    }
}

void solve() {
    string s;
    cin >> s;
    KMP(s);
    z_function(s);
    for (int i = 0; i < s.size(); i++) 
        cout << Z[i] << " ";
    cout << endl;
    for (int i = 0; i < s.size(); i++) 
        cout << pi[i] << " ";
    


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
