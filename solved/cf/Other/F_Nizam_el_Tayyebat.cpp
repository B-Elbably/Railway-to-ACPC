#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> freq;
    for (int i = 0; i < n; ++i) {
        freq[s[i] == 'L']++;
    }
    map<char, int> mp;
    for (int i = 0; i < n - 1; ++i) {
        int op = s[i] == 'L';
        mp[op]++;
        freq[op]--;
        if (mp[op] == freq[op]) continue;
        if (mp[op ^ 1] == freq[op ^ 1]) continue;
        cout << i + 1 << endl;
        return;
    }
    cout << -1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
