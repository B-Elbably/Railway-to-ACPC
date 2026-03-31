#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

vector<int> arr;
int n, a, b;

struct DSU {
    map<int, int> parent;
    DSU(int n) {
        for (int i = 0; i < n; i++) parent[arr[i]] = arr[i];
        for (int i = -2; i < 0; i++) parent[i] = i;
    }
    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) parent[u] = v;
    }
};

void solve() {
    cin >> n >> a >> b;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    DSU dsu(n);
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int ok1 = dsu.parent.count(a - arr[i]);
        int ok2 = dsu.parent.count(b - arr[i]);
        if (ok1) {
            dsu.unite(arr[i], a - arr[i]);
        }else{
            dsu.unite(arr[i], -1);
        }
        if (ok2) {
            dsu.unite(arr[i], b - arr[i]);
        }else{
            dsu.unite(arr[i], -2);
        }
    }
    if (dsu.find(-1) == dsu.find(-2)) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        int ans = 0;
        if (dsu.find(arr[i]) == dsu.find(-1)) {
            ans = 1;
        }
        cout << ans << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
