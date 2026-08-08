#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct point {
    int x, y, a, r, id;
};

using T = long double;
const T PI = acos(-1.0);
void solve() {
    int n;
    cin >> n;
    vector<point> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i].x >> f[i].y >> f[i].a >> f[i].r;
        f[i].id = i + 1;
    }    
    vector<vector<int>> adj(n);
    vector<int> in(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            T dx = f[j].x - f[i].x;
            T dy = f[j].y - f[i].y;
            T angle = atan2(dy, dx) * 180.0 / PI;
            if (angle < 0) angle += 360.0;
            T diff = abs(angle - f[i].a);
            diff = min(diff, 360.0 - diff);

            if (diff - f[i].r <= 1e-9) {
                adj[i].push_back(j);
                in[j]++;
            }
        }
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) q.push(i);
    }
    
    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(f[u].id);
        
        for (int v : adj[u]) {
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
    
    if (order.size() == n) {
        for (int i = 0; i < n; i++) {
            cout << order[i] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while (t--) solve();
    
    return 0;
}