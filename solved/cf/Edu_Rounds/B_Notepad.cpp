#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s += "$$";
    map<string, int> freq;
    for (int i = 1; i < n; ++i) {
        string t = s.substr(i - 1, 2);
        string r = s.substr(i, 2);
        if (freq[r]) {
            cout << "YES\n";
            return;
        }
        freq[t]++;
    }
    cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
