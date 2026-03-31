#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), a(n);
    for (int &x : p) cin >> x;
    for (int &x : a) cin >> x;
    vector<int> b = {a[0]};
    for (int i = 1; i < n; i++) {
        if (b.back() != a[i]) {
            b.push_back(a[i]);
        }
    }
    int j = 0;
    for (int i = 0; i < n && j < b.size(); i++) {
        if (p[i] == b[j]) {
            j++;
        }
    }
    
    if (j == b.size()) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}