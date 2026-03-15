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
    if (n & 1 && s[0] == 'b') {
        cout << "NO\n";
        return;
    }
    for (int i = n & 1; i < n; i += 2) {
        if (s[i] == s[i + 1] && s[i] != '?') {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
