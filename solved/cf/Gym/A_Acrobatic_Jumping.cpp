#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    if (n < 4) {
        cout << n << endl;
        return;
    }
    int add = 2;
    int sum = 2;
    int op = 2;
    while (sum < n) {
        sum += add;
        op ++;
        if (sum >= n) break;
        sum += add++;
        op ++;
    }
    cout << op << endl;
}

// 1 + 2 + ? + 2 + 1

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
