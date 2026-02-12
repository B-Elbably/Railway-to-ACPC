#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    y1 -= y0; x1 -= x0;
    int n; cin >> n;
    string s; cin >> s;

    int dx = 0, dy = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') dy++;
        else if (s[i] == 'D') dy--;
        else if (s[i] == 'R') dx++;
        else if (s[i] == 'L') dx--;
    }
    int l = 0, r = 1e15;
    while (l <= r) {
        int mid = (l + r) / 2;
        int X = mid / n * dx;
        int Y = mid / n * dy;
        for (int i = 0; i < mid % n; i++) {
            if (s[i] == 'U') Y++;
            else if (s[i] == 'D') Y--;
            else if (s[i] == 'R') X++;
            else if (s[i] == 'L') X--;
        }
        X -= x1; Y -= y1;
        if (abs(X) + abs(Y) <= mid) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (l >= 1e15) l = -1;
    cout << l << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}