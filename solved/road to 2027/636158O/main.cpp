#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[(i + 1) % x].push_back(a[i]);
    }
    for (int i = 0; i < x; ++i) {
        sort(all(mp[i]));
    }
    vector<int> c;
    for (int i = 0; i < n; ++i) {
        c.push_back(mp[(i + 1) % x][i / x]);
    }
    vector<int> b = a;
    sort(all(b));
    if (b == c) {
        cout << "YES" << endl;
    }else cout << "NO" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
