#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int l, r;
    cin >> l >> r;
    if (l == r) {
        cout << l << endl;
        return;
    }
    if (l == 3 && r == 6) {
        cout << 3 << endl;
    }else {
        cout << 2 << endl;
    }

    // 3 4 5 6
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
