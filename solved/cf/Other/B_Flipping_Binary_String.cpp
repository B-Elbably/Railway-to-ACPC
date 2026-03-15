#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;  cin >> n;
    string s; cin >> s;
    vector<int> one, zero;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') one.push_back(i + 1);
        else zero.push_back(i + 1);
    }
    if (one.size() % 2 == 0) {
        cout << one.size() << endl;
        for (int i : one) cout << i << ' ';
        cout << endl;
    } 
    else if (zero.size() % 2 == 1) {
        cout << zero.size() << endl;
        for (int i : zero) cout << i << ' ';
        cout << endl;
    } 
    else {
        cout << -1 << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) solve();
}