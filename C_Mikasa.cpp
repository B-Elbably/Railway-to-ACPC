#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int mex(set<int>& s) {
    int res = 0;
    while (s.count(res)) res++;
    return res;
}

void solve() {
    int n, m; 
    cin >> n >> m;
    m++;
    int ans = 0;
    for (int j = 30; j >= 0; j--) {
        int op1 = (n >> j) & 1;
        int op2 = (m >> j) & 1;
        if (op1 == op2) continue;
        if ( op1 < op2) ans |= (1LL << j);
        else break;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
