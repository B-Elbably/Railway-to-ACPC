#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e6 + 5;
int ans[N], prime[N], res[N];
void build() {
    fill(ans, ans + N, 0);
    fill(prime, prime + N, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i < N; ++i) {
        if (prime[i] == 1) {
            for (int j = i * i; j < N; j += i) {
                prime[j] = 0;
                ans[j] = ans[j / i] + 1;
            }
        }
    }
    for (int i = 2; i < N; ++i) {
        res[i] += prime[ans[i] + 1] + res[i - 1];
    }
}
void solve() {
    int n;
    cin >> n;
    // vector<int> a(n);
    // for (auto &x : a) cin >> x;
    cout << res[n] << endl;
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
