#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int H, G;
vector<pair<int, int>> cow0, cow1;
int memo[1005][1005][2];

int distSq(pair<int, int> a, pair<int, int> b) {
    int x = a.first - b.first;
    int y = a.second - b.second;
    return x * x + y * y;
}

int dfs(int h, int g, int type) {
    if (h == H && g == G && type == 0) return 0;
    if (h > H || g > G) return 1e18;
    if (h == H && type == 0) return 1e18;
    
    if (~memo[h][g][type]) return memo[h][g][type];

    int ans = 1e18;

    if (type == 0) {
        if (h < H) ans = min(ans, dfs(h + 1, g, 0) + distSq(cow0[h], cow0[h + 1]));
        if (g < G) ans = min(ans, dfs(h, g + 1, 1) + distSq(cow0[h], cow1[g + 1]));
    }
    if (type == 1) {
        if (h < H) ans = min(ans, dfs(h + 1, g, 0) + distSq(cow1[g], cow0[h + 1]));
        if (g < G) ans = min(ans, dfs(h, g + 1, 1) + distSq(cow1[g], cow1[g + 1]));
    }

    return memo[h][g][type] = ans;
}

void solve() {
    cin >> H >> G;
    cow0.resize(H + 1);
    cow1.resize(G + 1);
    for (int i = 1; i <= H; ++i) cin >> cow0[i].first >> cow0[i].second;
    for (int i = 1; i <= G; ++i) cin >> cow1[i].first >> cow1[i].second;
    memset(memo, -1, sizeof(memo));

    cout << dfs(1, 0, 0) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    int t = 1;
    while (t--) solve();
}