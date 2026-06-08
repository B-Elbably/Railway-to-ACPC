#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    multiset<int> s_set, d_set;
    
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        s_set.insert(x + y);
        d_set.insert(x - y);
        int ans1 = *s_set.rbegin() - *s_set.begin();
        int ans2 = *d_set.rbegin() - *d_set.begin();
        cout << max(ans1, ans2) << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
