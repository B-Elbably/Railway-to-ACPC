#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> go(27);
    vector<string> a(n);
    vector<vector<int>> cost(27, vector<int>(27, 1e9));
    for (auto &x : a) {
        cin >> x;
        for (int i = 0; i < 26; ++i) {
            for (char c : x) {
                if (c - 'a' == i) {
                    cost[i][x.back() - 'a'] = 1;
                    cost[x.back() - 'a'][i] = 1;
                }
            }
        }
    }
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            if (cost[i][k] == 1e9) continue;    
            for (int j = 0; j < 26; j++) {
                if (cost[k][j] == 1e9) continue;
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (cost[i][j] == 1e9) continue;
            go[i] |= (1 << j);
        }
    }
    while (q--) {
        string s, t;
        cin >> s >> t;
        bool ok = 0;
        int ans = 0;
        for (int x: s) ans |= go[x - 'a'];
        for (int x: t) {
            if (ans & (1 << (x - 'a'))) {
                ok = 1;
                break;
            }
        }
        cout << (ok ? "LUA" : "RYEI") << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
