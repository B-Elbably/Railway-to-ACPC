#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    string s;
    cin >> n >> s;
    // s += "";
    int ans = 4;
    string target = "ecpc";
    for (int i = 0; i < n - 3; ++i) {
        int res = 4;
        for (int j = 0; j < 4; ++j) {
            res -= target[j] == s[i + j];
            // cout << target[j] << " " << s[i + j];
        }
        // cout << "\n";
        ans = min(ans, res);
    }  
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
