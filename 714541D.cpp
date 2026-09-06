#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int a, x, y;
    cin >> a >> x >> y;
    if (y <= 0) {
        cout << -1 << endl;
        return;
    }
    if (y % a == 0) {
        cout << -1 << endl;
        return;
    } 
    int lx = -a;
    int rx = a;
    if (lx > x || rx < x) {
        cout << -1 << endl;
        return;
    }
    int lvl = (y + a - 1) / a;
    // cout << "lvl: " << lvl << endl;
    if (!lvl) {
        cout << -1 << endl;
        return;
    }
    if (lvl <= 2) {
        if (a > abs(x) * 2) {
            cout << lvl << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }
    lvl -= 2;
    int pos = lvl / 2;
    
    if (lvl & 1) {
        if (x == 0) {
            cout << -1 << endl;
            return;
        }
        if (abs(x) < a) {
            cout << 3 + (x > 0) + pos * 3 << endl;
            return;
        }
    } else {
        if (abs(x) * 2 < a) {
            cout << 2 + pos * 3 << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }
    cout << -1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
