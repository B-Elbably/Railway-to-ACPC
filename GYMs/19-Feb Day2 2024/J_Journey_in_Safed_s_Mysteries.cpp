#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.size(); i+= 2) {
        cout << s[i];
    }
    for (int i = s.size() - 1 - (s.size() & 1); i > 0; i -= 2) {
        cout << s[i];
    }
    cout << endl;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '/') cout << '/';
        else cout << t[i] - 'A';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
