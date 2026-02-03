
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
        cout << i + 1 << " " << i + 2 << "\n"; 
    }
    cout << n * m + 1 << " " << 1 << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}