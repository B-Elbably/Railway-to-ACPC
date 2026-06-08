#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, q;
    cin >> n >> q;
    bool rev, ok1, ok2;
    rev = ok1 = ok2 = false;

    while (q--) {
        char c; cin >> c;
        if (c == 'q') {
            int i, j; cin >> i >> j;
            if (ok1) i = n - i + 1;
            if (ok2) j = n - j + 1;
            if (rev) swap(i, j);    
            cout << (i - 1) * n + j << "\n";
        }else {
            char ax; cin >> ax;
            if (ax == 'a') {
                rev ^= 1;
                swap(ok1, ok2);
            }
            else if (ax == 'b') {
                ok2 ^= 1;
            }
            else if (ax == 'c') {
                rev ^= 1;
                swap(ok1, ok2);
                ok1 ^= 1; ok2 ^= 1;
            }
            else if (ax == 'd') {
                ok1 ^= 1;
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
