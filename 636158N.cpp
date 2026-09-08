#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int o;
    int a = 0, b = 0, c = 0, d = 0;
    cin >> o;
    if (o == 1) cin >> a;
    else if (o == 2) cin >> b;
    cin >> o;
    if (o == 3) cin >> c;
    else if (o == 4) cin >> d;

    if (!a) {
        a = 90 - b;
    }else {
        b = 90 - a;
    }

    if (!c) {
        c = 180 - d - b; 
    }else {
        d = 180 - c - b;
    }
    if (a <= 0 || b <= 0 || c <= 0 || d <= 0) {
        cout << -1 << endl;
        return;
    }
    if (a + b == 90 && c + d + b == 180) {
        cout << a << " " << b << " " << c << " " << d << endl;
    }else cout << -1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
