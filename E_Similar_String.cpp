#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for (char &x : s) {
        if (x == 'l') x = '1';
        else if (x == 'o') x = '0';
    }
    for (char &x : t) {
        if (x == 'l') x = '1';
        else if (x == 'o') x = '0';
    }
    cout << (s == t ? "Yes" : "No") << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
