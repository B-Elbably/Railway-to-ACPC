#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> good(n), bad(n);
    for (int i = 0; i < n; i++) {
        cin >> good[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> bad[i];
    }
    int ans = 0;
    for (int i = 0; i < m - 2; ++i){
        for (int j = i + 1; j < m - 1; ++j){
            for (int k = j + 1; k < m; ++k){
                set<string> patterns;
                for (int x = 0; x < n; ++x){
                    string pattern = "";
                    pattern += good[x][i];
                    pattern += good[x][j];
                    pattern += good[x][k];
                    patterns.insert(pattern);
                }
                bool valid = true;
                for (int x = 0; x < n; ++x){
                    string pattern = "";
                    pattern += bad[x][i];
                    pattern += bad[x][j];
                    pattern += bad[x][k];
                    if (patterns.count(pattern)){
                        valid = false;
                        break;
                    }
                }
                if (valid) ans++;
            }
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
