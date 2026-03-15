#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i - 1]) ans++;
    }
    
    while (m--) {
        int l, r;
        cin >> l >> r;
        int x = a[l], y = a[r];
        
        set<pair<int, int>> pairs;
        if (x > 1) pairs.insert({x - 1, x});
        if (x < n) pairs.insert({x, x + 1});
        if (y > 1) pairs.insert({y - 1, y});
        if (y < n) pairs.insert({y, y + 1});
        
        for (auto p : pairs) {
            if (pos[p.first] > pos[p.second]) ans--;
        }
        
        swap(a[l], a[r]);
        pos[x] = r;
        pos[y] = l;
        
        for (auto p : pairs) {
            if (pos[p.first] > pos[p.second]) ans++;
        }
        
        cout << ans << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}