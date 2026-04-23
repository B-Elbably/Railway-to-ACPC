#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int inf = 1e9;
void solve() {
    int n;
    cin >> n;
    int x1 = inf, y1 = inf, x2 = -inf, y2 = -inf;
    
    while (n--) {
        int x,y;
        cin >> x >> y;
        x1 = min(x1, x);
        x2 = max(x2, x);
        y1 = min(y1, y);
        y2 = max(y2, y);
    }
    cout << x1 << " " << y1 << endl;
    cout << x2 << " " << y1 << endl;
    cout << x2 << " " << y2<< endl;
    cout << x1 << " " << y2<< endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
