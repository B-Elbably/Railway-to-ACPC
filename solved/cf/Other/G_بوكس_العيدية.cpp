#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e6 + 5;
ld ans[N];
void build () {
    ld sum = 0;
    for (int i = 1; i < N; i++) {
        sum += 1.0 / i;
        ans[i] *= sum;
    }
}
void solve() {
    int n;
    cin >> n;
    cout << ans[n] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    iota(ans, ans + N, 0);
    build();
    cout << fixed << setprecision(9);
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
