#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a) cin >> x;
    vector<int> idx(n);
    iota(all(idx), 0);
    do {
        int ok = 1;
        for (int i = 0; i < n - 1; ++i) {
            string &s1 = a[idx[i]];
            string &s2 = a[idx[i + 1]];
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                if (s1[j] != s2[j]) {
                    cnt++;
                }
            }
            ok &= (cnt == 1);
        }
        if (ok) {
            cout << "Yes" << endl;
            return;
        }
    } while (next_permutation(all(idx)));
    cout << "No" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
