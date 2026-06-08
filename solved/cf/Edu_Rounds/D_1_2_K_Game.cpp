#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    int ok = 0;
    if (k % 3 == 0) {
        n %= (k + 1);
        ok = (n == k);
    }
    ok |= (n % 3);
    cout << (ok ? "Alice" : "Bob") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
