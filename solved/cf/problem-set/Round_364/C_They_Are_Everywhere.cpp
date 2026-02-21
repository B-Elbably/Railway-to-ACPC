#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    string s;
    cin >> n >> s;
    set<char> chars = set<char>(all(s)), ref;
    vector<int> freq(52, 0);
    int ans = n;
    int l = 0;
    for (int r = 0; r < n; r++) {
        int idx = islower(s[r]) ? s[r] - 'a' : s[r] - 'A' + 26;
        freq[idx]++;
        ref.insert(s[r]);
        while (ref.size() == chars.size()) {
            ans = min(ans, r - l + 1);
            int lidx = islower(s[l]) ? s[l] - 'a' : s[l] - 'A' + 26;
            freq[lidx]--;
            if (freq[lidx] == 0) ref.erase(s[l]);
            l++;
        }
    }
    cout << ans;
} 

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
