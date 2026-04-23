#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e4 + 5;
// int grid[N][N], pref[N][N]; 
// void build (){
//     for (int i = 1; i <= N; i++) {
//         for (int j = 1; j <= N; j++) {
//             pref[i][j] = grid[i - 1][j - 1] 
//                             + pref[i - 1][j]
//                             + pref[i][j - 1] 
//                             - pref[i - 1][j - 1];
//         }
//     }
// }
// const int sq = 1e4 + 5;
void solve() {
    int p, q;
    cin >> p >> q;
    int cnt = p + q * 2;
    for (int i = 1; i * i <= cnt; ++i) {
        int l = 1, r = cnt;
        while (l <= r){
            int mid = (l + r) >> 1;
            int target = (2 * i + 1) * mid + i;
            // target += mid;
            if (target == cnt && (!(q > i * (mid + 1)))) {
                cout << i  << " " << mid << endl;
                return;
            }
            if (target > cnt) {
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        
    }
    cout << -1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // grid[0][0] = 4;
    // for (int i = 0; i < N; ++i) grid[i][0] = grid[0][i] = 3;
    // for (int i = 1; i < N; ++i) 
        // for (int j = 1; j < N; ++j) 
            // grid[i][j] = 2;
    // build();
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
