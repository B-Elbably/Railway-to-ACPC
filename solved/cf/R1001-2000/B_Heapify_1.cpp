#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int check(int n) {
    while (n > 0 && n % 2 == 0) n /= 2;
    return n;
}

void solve() {
    int n;
    cin >> n;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (check(i) != check(a)) {
            ok = false;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
