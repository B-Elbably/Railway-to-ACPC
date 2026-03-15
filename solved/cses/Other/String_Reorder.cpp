#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> freq(26, 0);
    int mx = 0;
    for (char c : s) {
        freq[c - 'A']++;
        mx = max(mx, freq[c - 'A']);
    }

    if (mx > (n + 1) / 2) {
        cout << "-1" << endl;
        return;
    }

    string res;
    int last = -1;
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int j = 0; j < 26; j++) {
            if (freq[j] == 0 || j == last) continue;
            freq[j]--; mx = 0;
            for (int k = 0; k < 26; k++) 
                mx = max(mx, freq[k]);
            if (mx <= (n - i) / 2) {
                res += (char)('A' + j);
                last = j;
                ok = true;
                break;
            }
            freq[j]++;
        }
        if (!ok) {
            cout << "-1" << endl;
            return;
        }
    }

    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}