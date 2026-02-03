#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {  
    string s;
    cin >> s;
    s += '#'; 
    int ans = 0, n = s.size(), cnt = 1;
    char prev = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] == prev) {
            cnt++;
        } else {
            ans += cnt - 1;
            cnt = 1;
            prev = s[i];
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
