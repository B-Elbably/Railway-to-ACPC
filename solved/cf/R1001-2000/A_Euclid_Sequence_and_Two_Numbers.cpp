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
    vector<int> b = a;
    sort(all(b)); reverse(all(b));
    bool ok = 1;
    for (int i = 2; i < n; ++i) {
        if (b[i] != (b[i - 2] % b[i - 1])) {
            ok = 0;
            break;
        }
    }
    // if (!ok) {
    //     ok = 1;
    //     swap(b[0], b[1]);
    //     for (int i = 2; i < n; ++i) {
    //         if (b[i] != (b[i - 2] % b[i - 1])) {
    //             ok = 0;
    //             break;
    //         }
    // }
    // }
    if (ok) cout << b[0] << ' ' << b[1] << endl;
    else cout << -1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
