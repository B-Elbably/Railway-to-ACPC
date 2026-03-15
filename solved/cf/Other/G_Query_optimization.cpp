#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl "\n"

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    set<pair<int,int>> s;
    unordered_map<int, set<int>> idx;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert({a[i], i});
        idx[a[i]].insert(i);
    }

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            int ai = a[i];
            s.erase({ai, i});
            idx[ai].erase(i);
            a[i] = x;
            s.insert({x, i});
            idx[x].insert(i);
        }

        else if (t == 2) {
            int x;
            cin >> x;
            if (!idx.count(x) || idx[x].empty()) cout << -1 << endl;
            else cout << *idx[x].begin() << endl;
        }

        else {
            cout << ((t == 4) ? s.rbegin()->first : s.begin()->first) << endl;
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
