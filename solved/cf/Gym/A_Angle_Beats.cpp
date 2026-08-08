#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

pair<int, int> angle(int a, int b) {
    int g = std::gcd(a, b);
    if (g != 0) {
        a /= g;
        b /= g;
    }
    if (a < 0 || (a == 0 && b < 0)) {
        a = -a;
        b = -b;
    }
    return {a, b};
}

pair<int, int> perpAngle(pair<int, int> p) {
    return angle(-p.second, p.first);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int dx = points[j].first - points[i].first;
            int dy = points[j].second - points[i].second;
            adj[i].push_back(angle(dx, dy));
        }
        sort(all(adj[i]));
    }

    for (int i = 0; i < q; i++) {
        int ax, ay;
        cin >> ax >> ay;
        int ans = 0;
        vector<pair<int, int>> dirs(n);
        
        for (int u = 0; u < n; u++) {
            int dx = points[u].first - ax;
            int dy = points[u].second - ay;
            pair<int, int> dir = angle(dx, dy);
            dirs[u] = dir;
            
            pair<int, int> perp = perpAngle(dir);
            auto [it1, it2] = equal_range(all(adj[u]), perp);
            ans += distance(it1, it2);
        }
        
        sort(all(dirs));
        for (int u = 0; u < n; ) {
            int v = u;
            while (v < n && dirs[v] == dirs[u]) v++;
            int c1 = v - u;
            
            pair<int, int> perp = perpAngle(dirs[u]);
            if (dirs[u] < perp) {
                auto [it1, it2] = equal_range(all(dirs), perp);
                ans += c1 * distance(it1, it2);
            }
            u = v;
        }
        
        cout << ans << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}