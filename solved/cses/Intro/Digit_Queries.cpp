#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int k; cin >> k; k--;
    int power = 1, num = 1;
    while (power * 9 * num < k) {
        k -= power++ * 9 * num;
        num *= 10;
    }
    num += k / power;
    cout << to_string(num)[k % power] << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
