#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x; 
    int gc = gcd(a[0], a[1]);
    for (int i = 0; i < n; ++i) {
        if (a[i] % gc) {
            cout << "NO"; return;
        }
        a[i] /= gc;
    }
}   

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
