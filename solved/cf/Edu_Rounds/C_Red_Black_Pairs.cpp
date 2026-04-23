#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
string s1, s2;
int n;
const int N = 2e5 + 5; 
int memo[N];

int go(int i) {
    if (i >= n) return (i > n ? 1e8: 0);
    int &ret = memo[i];
    if (~ret) return ret;
    int op1 = (s1[i] != s2[i]) + go(i + 1);
    int op2 = 1e8;
    if (i + 1 < n) {
        op2 = (s1[i] != s1[i + 1]);
        op2 += (s2[i] != s2[i + 1]) + go(i + 2);
    }
    ret = min(op1, op2);
    return ret;
}

void solve() {
    cin >> n;
    cin >> s1 >> s2;
    // memset(memo, -1, sizeof memo);
    for (int i = 0; i <= n; ++i) memo[i] = -1;
    cout << go(0) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
