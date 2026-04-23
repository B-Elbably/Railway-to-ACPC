#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int l1, r1, p1, d1;
    int l2, r2, p2, d2;
    cin >> l1 >> r1 >> p1 >> d1;
    cin >> l2 >> r2 >> p2 >> d2;
    int k; cin >> k;
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        ans += (p1 == p2);
        // p1 += (int)pow(-1, d1 ^ 1);
        if (p1 == l1) d1 = 1;
        else if (p1 == r1) d1 = 0;
        p1 += (d1 == 0 ? -1 : 1);
        
        // p2 += (int)pow(-1, d2 ^ 1) ;
        if (p2 == l2) d2 = 1;
        else if (p2 == r2) d2 = 0;
        p2 += (d2 == 0 ? -1 : 1);
    }
    cout << ans << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
