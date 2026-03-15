#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

// z = p^e
// n % z == 0;
// 24  = 2^3 * 3^1
// 64  = 2^6

// i * (i + 1) / 2 <= cnt;
// i ** 2 + i <= 2 * cnt;
// i <= sqrt(2 * cnt);

int factorize(int n) {
    int ans = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            int candy = sqrt(2 * cnt);
            while (candy * (candy + 1) > 2 * cnt) candy--;
            while ((candy + 1) * (candy + 2) <= cnt * 2) candy++;
            ans += candy;
        }
    }
    if (n > 1) ans++;
    return ans;
}
void solve() {
    int n;
    cin >> n;
    cout << factorize(n) << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
