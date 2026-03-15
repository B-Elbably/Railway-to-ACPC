#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int l = 0, r = 1e9 ;
    int cost = LLONG_MAX;
    while (r - l > 3)
    {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int cost1 = 0, cost2 = 0;
        for (auto x : a) {
            cost1 += abs(x - m1);
            cost2 += abs(x - m2);
        }
        cost = min({cost, cost1, cost2});
        if (cost1 < cost2) {
            r = m2;
        } else {
            l = m1;
        }
    }
    if (cost == LLONG_MAX) cost = 0;
    cout << cost;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
