#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    deque<int> a(n);
    for (auto &x : a) cin >> x;

    int last = 0;
    n -= 1;
    for (int i = 0; i <= n; ++i, n--) {
        if (i == n) {
            cout << "L";
            // cout << a[i] << " ";
            break;
        }
        if (last < a[i] && a[i] < a[n]) {
            cout << "RL";
            last = a[i];
            // cout << a[n] << " " << a[i] << " ";

        }else {
            // cout << a[i] << " " << a[n] << " ";
            cout << "LR";      
            last = a[n];      
        }
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
