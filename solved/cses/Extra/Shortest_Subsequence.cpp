#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int status = 0;
    string ans = "";
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') status |= 1;
        if (s[i] == 'C') status |= 2;
        if (s[i] == 'G') status |= 4;
        if (s[i] == 'T') status |= 8;
        if (status == 15) {
            ans += s[i];
            status = 0;
        }
    }
    if (!(status & 1)) ans += 'A';
    else if (!(status & 2)) ans += 'C';
    else if (!(status & 4)) ans += 'G';
    else ans += 'T';
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
