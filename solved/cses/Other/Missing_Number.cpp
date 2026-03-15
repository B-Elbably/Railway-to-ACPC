#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n - 1; i++) {
        int x; cin >> x;
        s.insert(x);
    }
    for (int i = 1; i <= n; i++) {
        if (!s.count(i)) {
            cout << i << endl;
            return;
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
