#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<pair<pair<string, int>, string>> a(n);
    for (int i = 0; i < n; i++) {
        string x; cin >> x; 
        int pos = x.find('-');
        a[i].second = x.substr(0, pos);
        a[i].first.first = x.substr(pos + 1);
        a[i].first.second = stoll(a[i].second);
    }
    sort(all(a));
    for (auto &p : a) {
        cout << p.second << "-" << p.first.first << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
