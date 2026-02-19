#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    map<int, int> a;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x] = i;
    }
    int q; cin >> q;
    int add = 0;
    while (q--) {
        int type, x; cin >> type >> x;
        if (type == 1) {
            // x = -x;
            x = (x % n + n) % n;
            add = (add + x) % n;
        }else {
            if (a.count(x)) {
                cout << (a[x] + add ) % n + 1 << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
