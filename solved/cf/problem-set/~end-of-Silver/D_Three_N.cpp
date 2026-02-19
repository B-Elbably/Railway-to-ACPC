#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void brute(int s) {
    for (int i = 1; i < s; ++i) {
        if (i > 3) break;
        for (int j = i + 1; j <= s - i; ++j) {
            for (int k = j + 1; k <= s - i + j; ++k) {
                if (j % i == 0 || k % i == 0) continue;
                if (i + j + k == s) {
                    cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
}
void solve() {
    int n;
    cin >> n;
    // cout << n << endl;
    // brute(n);
    if (n < 10 || n == 11 || n == 13) {
        cout << -1 << endl;
        return;
    }
    if (n & 1) {
        n -= 3;
        for (int i = 4; i <= n; ++i) {
            if (i % 3 == 0) continue;
            int k = n - i;
            if (k % 3 == 0) continue;
            cout << 3 << " " << i << " " << k << endl;
            break;
        }
    }else {
        cout << 2 << " " << 3 << " " << n - 5 << endl; 
    }
    // cout << "======\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
