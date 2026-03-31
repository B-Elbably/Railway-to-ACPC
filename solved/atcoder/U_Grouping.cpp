#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n;
const int N = 16;
int adj[N][N];
int memo[1 << N];
int group[1 << 18];

int go(int mask) {
    if (mask == 0) return 0;
    int &ret = memo[mask];
    if (~ret) return ret;
    ret = 0;
    for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
        if (sub & (1 << __builtin_ctz(mask))) {
            ret = max(ret, group[sub] + go(mask ^ sub));
        }
    }
    return ret;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
        int score = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                for (int j = i + 1; j < n; ++j) {
                    if (mask & (1 << j)) score += adj[i][j];
                }
            }
        }
        group[mask] = score;
    }
    memset(memo, -1, sizeof memo);
    cout << go((1 << n) - 1) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
