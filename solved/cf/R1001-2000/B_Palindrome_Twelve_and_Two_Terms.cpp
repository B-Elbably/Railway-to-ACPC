#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
bool ispal(int n) {
    string s = to_string(n);
    string t = s;
    reverse(all(t));
    return s == t;
}

// void brute() {
//     for (int n = 1; n < 1000000; ++n) {
//         int ok = 0;
//         for (int i = 0; i <= n; ++i) {
//             if (ispal(i) && (n - i) % 12 == 0) {
//                 ok = 1;
//                 break;
//             }
//         }
//         if (!ok) {
//             cout << n << endl;
//         }
//     }
// }

void solve() {
    int n;
    cin >> n;
    // cout
    if (n == 10) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i <= n; ++i) {
        if (!ispal(i)) continue;
        if ((n - i) % 12 == 0) {
            cout << i << ' ' << n - i << endl;
            return;
        }
    }
    // if (n >= 22 && (n - 22) % 12 == 0) {
    //     cout << 22 << ' ' << n - 22 << endl;
    //     return;
    // }
    // cout << "==============================" << endl;
    // cout << "==============================" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // brute(/);
    // cot << "==============================" << endl;
    // cout << "==============================" << endl;
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
