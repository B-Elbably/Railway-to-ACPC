#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    set<int> s;
    int ans = n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        s.insert(u);
    }
    cout << (s.size() == n - 1 ? "YES" : "NO");
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
