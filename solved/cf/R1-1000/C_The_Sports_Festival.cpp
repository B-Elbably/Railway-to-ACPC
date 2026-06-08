#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 2005;
int memo[N][N];
vector<int> a;

int go(int l, int r) {
    if (a[l] == a[r]) return 0;
    int &ret = memo[l][r];
    if (~ret) return ret;
    ret = a[r] - a[l];
    int op1 = go(l + 1, r);
    int op2 = go(l, r - 1);
    ret += min(op1, op2);
    return ret;
}

void solve() {
    int n;
    cin >> n;
    a.resize(n);
    for (auto &x : a) cin >> x;
    sort(all(a));
    memset(memo, -1, sizeof memo);
    cout << go(0, n - 1);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
