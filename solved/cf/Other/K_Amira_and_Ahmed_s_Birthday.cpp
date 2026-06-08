#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int type, x; cin >> type >> x;
        if (type == 1) sum += x;
        else sum -= x;
        if (sum < 0) {
            if (i & 1) cout << "AHMED" << endl;
            else cout << "AMIRA" << endl;
            return;
        }
    }
    cout << "DRAW" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
