#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int N = 1e5 + 5;
vector<int> phi(N + 1);
vector<bool> prime(N + 1);
const int MOD = 1e9 + 7;
void build() {
    for (int i = 0; i <= N; i++) {
        phi[i] = i;
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (prime[i]) {
            for (int j = i; j <= N; j += i) {
                prime[j] = false;
                phi[j] -= phi[j] / i;
            }
        }
    }
    phi[1] = 1;
}

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    // for (int c = 1; c <= n; ++c) {
    //     for (int b = 1; b <= n; ++b) {
    //         int a = n - b - c;
    //         if (a <= 0) break;
    //         cout << a << " " << b << " " << c;
    //         if (gcd(a, b) == 1) cout << " -> ";
    //         else cout << " ->> ";
    //         int f = lcm(gcd(a, b), c);
    //         cout << f << endl;
    //         ans += f;
    //     }
    //     cout << ans << endl;
    // }
    for (int c = 1; c <= n - 2; ++c) {
        int ab = n - c;
        for (int d = 1; d * d <= ab; ++d) {
            if (ab % d) continue;
            // cout << c << " " << d << " " << phi[ab / d] << endl;
            if (ab / d > 1) 
                ans += lcm(c, d) * phi[ab / d];
            ans %= MOD;
            if (d * d == ab || d == 1) continue;
            int d2 = ab / d;
            // cout << c << " " << d << " " << phi[ab / d] << endl;
            ans += lcm(c, d2) * phi[ab / d2];
            ans %= MOD;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
