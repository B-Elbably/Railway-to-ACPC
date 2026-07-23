#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'


void solve() {
    int n;
    cin >> n;
    if (n <= 2) {
        cout << 0 << endl << endl;
        return;
    }
    cout << n - 1 << endl;
    for (int i = 0; i < n - 1; ++i) {
        if (i % 2 == 0) {
            if (i == n - 2) {
                cout << 'B';
            } else {
                cout << 'F';
            }
        } else {
            cout << 'B';
        }
    }
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
