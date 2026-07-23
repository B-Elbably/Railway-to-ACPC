#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 48;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> freq(n, vector<int>(N, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x; cin >> x;
            for (int k = 0; k < N; ++k) {
                if ((x >> k) & 1) freq[i][k]++;
            }
        }
    }
    // cout << "N";
    for (int k = 0; k < N; ++k) {
        int ok = 1;
        for (int i = 0; i < n; ++i) {
            if (!freq[i][k]) {ok = 0; break;}
        }
        if (ok) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
