#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    vector<pair<string, pair<int, int>>> a(n);
    for (int i = 0; i < n; ++i) {
        string x; cin >> x;
        v[i] = x;
        int idx = x.find('-');
        string p1 = x.substr(0, idx);
        string p2 = x.substr(idx + 1);
        a[i] = {p2, {stoll(p1), i}};
    }
    sort(all(a), [](const pair<string, pair<int, int>>& x, const pair<string, pair<int, int>>& y) {
        if (x.first == y.first) return x.second.first < y.second.first;
        return x.first < y.first;
    });
    
    for (int i = 0; i < n; ++i) {
        cout << v[a[i].second.second] << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
