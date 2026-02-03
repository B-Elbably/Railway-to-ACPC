#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    string s; cin >> s;
    vector<vector<int>> pos(s.size() + 1, vector<int>(26, 0));
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < 26; ++j) {
            pos[i + 1][j] = pos[i][j];
        }
        pos[i + 1][s[i] - 'a']++;
    }
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        if (l == r || s[l - 1] != s[r - 1]) {
            cout << "Yes" << endl;
            continue;
        }
        int cnt = 0;
        for (int j = 0; j < 26; ++j) {
            if (pos[r][j] - pos[l - 1][j] > 0) {
                cnt++;
            }
        }
        cout << (cnt >= 3 ? "Yes" : "No") << endl;
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
