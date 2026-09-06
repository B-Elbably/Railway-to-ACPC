#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    if (k * k < n) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for (int x = 1; x * k <= n; ++x) {
        int start = (x - 1) * k + 1;
        int end = x * k;
        for (int i = end; i >= start; --i) {
            cout << i << ' ';
        }
    }
    int l = n / k * k + 1;
    for (int i = n; i >= l; --i)
        cout << i << ' ';
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
