#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) % 2 == 0) {
                (grid[i][j] == 'A') ? grid[i][j] = 'B' : grid[i][j] = 'A';
            } else {
                (grid[i][j] == 'C') ? grid[i][j] = 'D' : grid[i][j] = 'C';
            }
        }
    }

    for (int i = 0; i < n; i++) 
        cout << grid[i] << endl;
    
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}


