#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int &x : a) cin >> x;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        adj[a[i]].push_back({b[i], i});
        adj[b[i]].push_back({a[i], i});
    }
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() % 2) {
            cout << -1 << endl;
            return;
        }
    }
    vector<int> ans;
    vector<bool> used(n);
    for (int i = 1; i <= n; i++) {
        int u = i;
        while (!adj[u].empty()) {
            auto [v, idx] = adj[u].back();
            adj[u].pop_back();
            if (used[idx]) continue;
            used[idx] = true;
            if (a[idx] != u) ans.push_back(idx + 1);
            u = v;
        }
    }
    for (int i : ans) {
        swap(a[i - 1], b[i - 1]);
    }
    multiset<int> sA(all(a)), sB(all(b));
    if (sA != sB) {
        cout << -1 << endl;
        return;
    }
    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}