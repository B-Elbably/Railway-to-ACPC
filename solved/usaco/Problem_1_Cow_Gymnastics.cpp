#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int k,n;
    cin >> k >> n;
    // !-$-!-$-!-$-!-$-!-$
    map<int, vector<int>> pos;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            int x; cin >> x;
            pos[x].push_back(j);
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            int ok = 1;
            for (int kk = 0; kk < k; ++kk) {
                if (pos[i][kk] > pos[j][kk]) {
                    ok = 0;
                    break;
                }
            }
            res += ok;
        }
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
