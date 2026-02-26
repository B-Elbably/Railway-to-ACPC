#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int open = 0;
    vector<int> ans(n);
    int one = 0, two = 0;
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            if (open >= 0) { ans[i] = 1; one = 1; }
            else { ans[i] = 2; two = 1; }
            open++;
        } else {
            if (open > 0) { ans[i] = 1; one = 1; }
            else { ans[i] = 2; two = 1; }
            open--;
        }
    }
    
    if (open != 0) {
        cout << -1 << "\n";
        return;
    }
    int k = one + two;
    cout << k << "\n";
    for (int i = 0; i < n; ++i) {
        cout << min(k, ans[i]) << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}