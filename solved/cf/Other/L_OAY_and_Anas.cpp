#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int sum = 0;
    for (char c : s) sum += (c == '1');
    
    int ans = sum; 
    for (int i = 0; i < k; ++i) {
        int now = 0;
        for (int j = i; j < n; j += k) {
            int add = (s[j] == '0' ? 1 : -1);
            now = max(0LL, now - add);
            ans = min(ans, sum - now);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}