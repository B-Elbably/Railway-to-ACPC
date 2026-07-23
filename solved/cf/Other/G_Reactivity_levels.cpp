#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (auto &x : a) cin >> x;
    sort(all(a));
    // nS = (n - 1) * S
    for (int i = 0; i < 3; ++i) {
        vector<int> b;
        for (int j = 0; j < n + 2; ++j){
            if (i == j) continue;
            b.push_back(a[j]);
        }
        vector<int> pref(n + 2, 0), suf(n + 2, 0);
        for (int j = 0; j < n + 1; ++j) pref[j + 1] = pref[j] + b[j];
        for (int j = n; j >= 0; --j) suf[j] = b[j] + suf[j + 1];
        // for (int i: pref) cout << i << " "; cout << "\n";
        // for (int i: suf) cout << i << " "; cout << "\n";
        // cout << i << ":\n";
        // for (int x: b) cout << x << " ";
        // cout << endl;
        for (int j = 0; j <= n; ++j) {
            int S = b[j];
            int nS = S * (n - 1);
            if (pref[j] + suf[j + 1] == nS) {
                vector<int> res;
                for (int k = 0; k <= n; ++k) {
                    if (k == j)continue;
                    // cout << S - b[k] << " ";
                    res.push_back(S - b[k]);
                }
                sort(all(res));
                if (res[0] >= 0) {
                    cout << S << " " << a[i] << endl;
                    for (int x: res) cout << x << " ";
                    return;
                }
            }
        }
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
