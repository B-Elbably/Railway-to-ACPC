#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int x11, y11, x12, y12;
    cin >> x11 >> y11 >> x12 >> y12;
    int x21, y21, x22, y22;
    cin >> x21 >> y21 >> x22 >> y22;

    int x31 = min(x11, x21);
    int y31 = min(y11, y21);
    int x32 = max(x12, x22);
    int y32 = max(y12, y22);
    int side = max(x32 - x31, y32 - y31);
    cout << side * side << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
