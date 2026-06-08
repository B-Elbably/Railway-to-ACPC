#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int bad[26];

void solve() {
    int n, k, l;
    cin >> n >> k >> l;
    string s;
    cin >> s;
    for (int i = 0; i < l; ++i) {
        char c; cin >> c;
        bad[c - 'a'] = 1;
    }
    unordered_map<int, int> freq;
    freq[0] = 1;
    int sum = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        sum += bad[s[i] - 'a'];
        if (sum >= k) ans += freq[sum - k];
        freq[sum]++;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
