#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int l = 0, r = 0, ans = 0;
    multiset<int> ms;
    while (r < n) {
        ms.insert(a[r]);
        while (*ms.rbegin() - *ms.begin() > x) {
            ms.erase(ms.find(a[l]));
            l++;
        }
        ans += r - l + 1;
        r++;
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
