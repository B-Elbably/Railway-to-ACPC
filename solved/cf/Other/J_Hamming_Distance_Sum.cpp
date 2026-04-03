#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    vector<int> pref(m + 1, 0);
    for (int i = 0; i < m; i++) {
        pref[i + 1] = pref[i] + (b[i] - '0');
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i; 
        int r = m - n + i;
        if (a[i] == '0') {
            ans += pref[r + 1] - pref[l];
        } else {
            ans += (r - l + 1) - (pref[r + 1] - pref[l]);
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}