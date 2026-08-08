#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct point {
    int x, y, p;
};

int calc(point a, point b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int add(point a, point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void solve() {
    int n;
    cin >> n;
    vector<point> a(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y >> a[i].p;
    cin >> a[0].x >> a[0].y; a[0].p = 0;
    cin >> a[n + 1].x >> a[n + 1].y; a[n + 1].p = 0;

    vector<vector<int>> dist(n + 2, vector<int>(n + 2, LLONG_MAX));
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            if (i == j) continue;
            int d = calc(a[i], a[j]);
            if (i >= 1 && i <= n && j >= 1 && j <= n && d <= a[i].p * a[i].p) {
                dist[i][j] = min(add(a[i], a[j]), 2LL);
            } else {
                dist[i][j] = add(a[i], a[j]);
            }
        }   
    }
    for (int k = 0; k <= n + 1; k++) {
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= n + 1; j++) {
                if (dist[i][k] == LLONG_MAX || dist[k][j] == LLONG_MAX) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    cout << dist[0][n + 1] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}