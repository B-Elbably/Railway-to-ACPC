#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int m;
vector<int> a;
int sum(vector<int> &ind){
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            int mx = a[ind[i]];
            for (int k = ind[i]; k <= ind[j]; k++) {
                mx = max(mx, a[k]);
            }
            ans += mx;
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    a.resize(n);
    for (auto &x : a) cin >> x;
    int q; cin >> q;
    while (q--) {
        cin >> m;
        vector<int> ind(m);
        for (auto &x : ind) cin >> x, x--;
        cout << sum(ind) << endl;
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
