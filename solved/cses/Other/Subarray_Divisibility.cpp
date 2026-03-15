#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> count;
    count[0]++;
    int pref = 0, ans = 0;
    for (auto &x : a) {
        cin >> x;
        pref = (pref + x % n + n) % n;
        if (count.count(pref)) {
            ans += count[pref]++;
        } else {
            count[pref] = 1;
        }
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
