#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, int> freq;
    for (int i = 0; i < n; ++i) freq[a[i]]++;
    vector<int> ans(n);
    set<int> used;
    for (int i = 1; i <= n + 2; ++i) { 
        used.insert(i);
    }
    map<int, set<int>> mp;
    map<int, int> good;
    for (auto [k, v] : freq) {
        int sz = n - k;
        if (v % sz) {
            cout << "Impossible\n";
            return;
        }
        int cnt = v / sz;
        for (int i = 0; i < cnt; i++) {
            int candy = *used.begin();
            used.erase(used.begin());
            mp[k].insert(candy);
            good[candy] = sz;
        }
    }
    for (int i = 0; i < n; ++i) {
        int ai = a[i];
        while (!mp[ai].empty()) {
            int candy = *mp[ai].begin();
            ans[i] = candy;
            if (--good[candy] == 0)
                mp[ai].erase(mp[ai].begin());

            break;
        }
        if (ans[i] == 0) {
            cout << "Impossible" << endl;
            return;
        }
    }
    for (auto [k , v]: good) {
        if (v) {
            cout << "Impossible" << endl;
            return;
        }
    }
    cout << "Possible" << endl;
    for (auto x: ans) cout << x << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
