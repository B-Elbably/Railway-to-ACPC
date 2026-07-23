#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int ask(int u, int v) {
    cout << "? " << u << " " << v << endl;
    cout.flush();
    int res; cin >> res;
    return res;
} 

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> ans;
    for (int i = 2; i <= n; ++i) {
        int u = 1;
        int v = i;
        int w = ask(u, v);
        while (w != u && w != v) {
            u = w;
            w = ask(u, v);
        }
        ans.push_back({u, v});  
    }
    cout << "! ";
    for (auto [u, v] : ans) {
        cout << u << " " << v << " ";
    }
    cout << endl;
    cout.flush();
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
