#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 5e5 + 5;
struct query {
    int x, y, type;
};

void solve() {
    int q; cin >> q;
    int n = 0;
    vector<query> queries(q);
    for (int i = 0; i < q; ++i) {
        int type; cin >> type;
        if (type == 1) {
            n++;
            int x; cin >> x;
            queries[i] = {x, 0, 1};
        } else {
            int x, y; cin >> x >> y;
            queries[i] = {x, y, 2};
        }
    }
    vector<int> ans(n);
    vector<int> mp(N);
    iota(all(mp), 0);
    int j = n - 1;
    for (int i = q - 1; i >= 0; --i) {
        if (queries[i].type == 2) {
            mp[queries[i].x] = mp[queries[i].y];
        }else {
            ans[j--] = mp[queries[i].x];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
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
