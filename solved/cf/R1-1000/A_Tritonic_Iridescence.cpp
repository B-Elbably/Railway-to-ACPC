#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '?' + s + '?';
    for (int i = 1; i < n; ++i) {
        if (s[i] == '?') continue;
        if (s[i] == s[i + 1]) {
            cout << "No" << endl;
            return;
        }
    }
    bool ok = s.find("??") != string::npos;
    ok |= s.find("C?C") != string::npos;
    ok |= s.find("M?M") != string::npos;
    ok |= s.find("Y?Y") != string::npos;
    if (ok) {
        cout << "Yes";
        return;
    }
    cout << "No" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
