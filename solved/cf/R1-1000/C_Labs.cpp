#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int cnt = 1;
    for (int j = 0; j < n; ++j) {
        if ((j & 1) == 0){
            for (int i = 0; i < n; ++i) {
                ans[i][j] = cnt++;
            }
        }else {
            for (int i = n - 1; i >= 0; i--){
                ans[i][j] = cnt++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    // 1 6 7 
    // 2 5 8 
    // 3 4 9
}   

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
