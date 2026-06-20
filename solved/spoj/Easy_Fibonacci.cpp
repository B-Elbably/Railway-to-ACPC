#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e6 + 5;
const int MOD = 1e8 + 7;
int f[N];
void precompute() {
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < N; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    }
}

void solve() {
    int n;
    cin >> n;
    cout << f[n] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
