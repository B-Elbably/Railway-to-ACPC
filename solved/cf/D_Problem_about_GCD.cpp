#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int l , r , g;
    cin >> l >> r >> g;
    int L = (l + g - 1) / g * g;
    int R = r - r % g;

    for (int i = 0; 1000; ++i){
        for (int j = 0; j <= i; ++j){
            int nL = L + j * g;
            int nR = R - (i - j) * g;
            if (nR < nL || nL > r || nR < l) break;
            if (gcd(nL, nR) == g) {
                cout << nL << " " << nR << "\n";
                return;
            }
        } 
        if (L + (i + 1) * g > r) break;
    }
    cout << "-1 -1" << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
