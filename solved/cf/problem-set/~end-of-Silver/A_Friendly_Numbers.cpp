#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int sum_of_digits(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int brute(int n) {
    int cnt = 0;
    for (int i = max(0LL, n - 100); i <= n + 100; i++) {
        if (i - sum_of_digits(i) == n) {
            cnt++;
        }
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    cout << brute(n) << endl;
    // for (int n = 1; n <= 10000; n++) {
    //     int ans = brute(n);
    //     if (n % 9 == 0 && ans == 0) {
    //         cout << n << " " << ans << endl;
    //     }
    //     if (ans == 0) continue;
    //     // cout << n << " " << brute(n) << endl;
    // }
    // cout << (n % 9 == 0 ? 10 : 0) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
