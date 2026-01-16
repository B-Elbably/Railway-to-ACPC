#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int x, n, m;
    cin >> x >> n >> m;
    // cout << bitset<30>(x) << endl;
    n = min(n, 31);
    m = min(m, 31);
    int cx = x, cn = n, cm = m;
    for (;cn + cm && cx;) {
        if (cm) {
            cx = (cx + 1) >> 1;
            cm--;
            if (cx == 1 && cn) cx = 0;
            continue;
        }
        if (cn) {
            cx = cx >> 1;
            cn--;
            continue;
        }
        
    }
    cout << cx << " ";
    cx = x, cn = n, cm = m;
    for (;cn + cm && cx;) {
        if (cn) {
            cx = cx >> 1;
            cn--;
            continue;
        }
        if (cm) {
            if (cx == 1) break;
            cx = (cx + 1) >> 1;
            cm--;
            continue;
        }
    }
    cout << cx << "\n";
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t; 
    while (t--) solve();
}