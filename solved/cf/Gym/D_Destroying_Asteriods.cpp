#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int r, c, l;
    cin >> r >> c >> l;
    vector<int> freq(r + 1, 0);
    for (int i = 0; i < c; i++) {
        int x; cin >> x;
        freq[x]++;
    }

    vector<int> v;
    for (int i = 1; i <= r; i++) {
        if (freq[i]) v.push_back(freq[i]);
    }

    sort(all(v));
    reverse(all(v));
    int ans = 0;
    for (int i = 0; i < min(l, (int)v.size()); i++) {
        ans += v[i];
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
