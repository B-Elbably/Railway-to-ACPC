#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long D[N];

void precompute() {
    D[0] = 1;
    D[1] = 0;
    for (int i = 2; i < N; i++) {
        D[i] = (i - 1) * (D[i - 1] + D[i - 2]) % MOD;
    }
}

void solve() {
    int n;
    cin >> n;
    // for (int i = 0; i <= n; i++) {
    //     cout << D[i] << " ";
    // }
    cout << D[n] << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
