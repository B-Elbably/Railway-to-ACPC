#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> good(n), bad(n);
    for (int i = 0; i < n; i++) {
        cin >> good[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> bad[i];
    }
    int ans = 0;
    for (int i = 0; i < m; ++i){
        set<char> g, b;
        for (int j = 0; j < n; ++j){
            g.insert(good[j][i]);
            b.insert(bad[j][i]);
        }
        set<char> inter;
        set_intersection(all(g), all(b), inserter(inter, inter.begin()));
        ans += inter.size() == 0;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
