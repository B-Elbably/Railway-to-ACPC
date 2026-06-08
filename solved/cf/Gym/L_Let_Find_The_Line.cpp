#include <bits/stdc++.h>
using namespace std;

char ask(int x) {
    cout << "? " << x << endl;
    char c; cin >> c;
    return c;
}

void solve() {
    int l = 1, r;
    cin >> r;
    int mx = 1e9;
    while (l < r) {
        int m = (l + r) >> 1;
        char c = ask(m);
        if (c != '<') {
            if (c == '>') mx = min(mx, m);
            r = m;
        } else {
            l = m + 1;
        }
    }
    int lx = l;
    r = min(mx, l + 1000000);
    while (l < r) {
        int m = (l + r + 1) >> 1;
        char c = ask(m);
        if (c == '=') {
            l = m;
        }else {
            r = m - 1;
        }
    }
    cout << "! " << (r - lx + 1) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;    
    while (t--) solve();
    return 0;
}
