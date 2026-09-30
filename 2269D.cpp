#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

vector<int> a;

void build(){
    for (int i = 1; i <= 16; ++i) {
        cout << i << " : ";
        for (int j = 1; j <= 5; ++j) {
            cout << (i ^ (j * 3)) << " ";
        }
        cout << endl;
    }
}
// 1 2 4 7 8 11 13 14 16

void solve() {
    int n, q;
    cin >> n >> q;
    a.resize(n);
    for (auto &x : a) cin >> x;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 5 == 0) {
            a[i] = 3;
        }
        ans += (a[i] % 3 == 0);
    }
    cout << ans << " ";
    while (q--) {
        int idx, x;
        cin >> idx >> x; idx--;
        if (x % 5 == 0) {
            x = 3;
        }
        ans -= (a[idx] % 3 == 0);
        a[idx] = x;
        ans += (a[idx] % 3 == 0);
        cout << ans << " ";
    }
    cout << endl;    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // build();
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}