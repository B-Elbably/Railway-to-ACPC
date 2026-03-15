#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    if (n <= 3) {
        cout << "NO SOLUTION" << endl;
        return;
    }
    for (int i = n - (n % 2 == 0); i > 0; i -= 2) {
        cout << i << " ";
    }
    for (int i = n - (n % 2 == 1); i > 0; i -= 2) {
        cout << i << " ";
    }
    cout << endl;
    // 3 1 4 2 5
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
