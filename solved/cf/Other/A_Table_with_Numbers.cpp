#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, h, l;
    cin >> n >> h >> l;

    int R = 0, C = 0, go = 0;

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x <= h && x <= l) go++;
        else if (x <= h) R++;
        else if (x <= l) C++;
    }

    int ans = 0;
    int m = min(R, C);
    ans += m;
    R -= m; C -= m;

    m = min(R, go);
    ans += m;
    R -= m; go -= m;

    m = min(C, go);
    ans += m;
    C -= m; go -= m;

    ans += go / 2;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
