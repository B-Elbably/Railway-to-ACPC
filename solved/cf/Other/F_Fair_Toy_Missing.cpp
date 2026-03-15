#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n = 5;
    set<int> s, t;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.insert(x);
    }
    for (int i = 0; i < n - 1; i++) {
        int x; cin >> x;
        t.insert(x);
    }
    for (int x : s) {
        if (t.count(x) == 0) {
            cout << x << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
