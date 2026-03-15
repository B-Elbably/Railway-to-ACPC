#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 5e5 + 1; 

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(1 << 10, 0);
    int mask = 0;
    cnt[0] = 1;
    int ans = 0;
    for (char c : s) {
        mask ^= (1 << (c - '0'));
        ans += cnt[mask]++;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
