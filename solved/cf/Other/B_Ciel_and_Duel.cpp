#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> attack, defense;
    multiset<int> me, me2; 
    
    for (int i = 0; i < n; ++i) {
        string s; int x;
        cin >> s >> x;
        if (s == "ATK") attack.push_back(x);
        else defense.push_back(x);
    }
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        me.insert(x); me2.insert(x);
    }
    sort(all(attack));
    sort(all(defense)); 

    int ans1 = 0;
    for (int i = 0; i < attack.size(); ++i) {
        if (me.empty()) break;
        auto it = me.rbegin();
        if (*it < attack[i]) break;
        ans1 += *it - attack[i];
        me.erase(me.find(*it));
    }

    int ans2 = 0;
    bool ok = true;
    for (int x : defense) {
        auto it = me2.upper_bound(x);
        if (it == me2.end()) { ok = false; break; }
        me2.erase(me2.find(*it));
    }
    if (ok) {
        for (int x : attack) {
            auto it = me2.lower_bound(x);
            if (it == me2.end()) { ok = false; break; }
            ans2 += *it - x;
            me2.erase(me2.find(*it));
        }
        if (ok) {
            for (int x : me2) ans2 += x;
        }
    }
    if (!ok) ans2 = 0;
    cout << max(ans1, ans2) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}