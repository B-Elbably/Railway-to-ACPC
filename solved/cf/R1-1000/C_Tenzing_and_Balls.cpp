#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
const int N = 2e5 + 5;
int memo[N];
int n;
vector<int> a;
vector<int> best;

int go(int i) {
    if (i == n) return 0;
    int &ret = memo[i];
    if (~ret) return ret;
    ret = go(i + 1);
    if (i + 1 < n) {
        best[a[i + 1]] = max(best[a[i + 1]], (i + 1) + go(i + 2));
    }
    if (best[a[i]] > -1e18) {
        ret = max(ret, best[a[i]] - i + 1);
    }
    return ret;
}

void solve() {
    cin >> n;
    for (int i = 0; i <= n; i++) memo[i] = -1;
    a.resize(n);
    for (auto &x : a) cin >> x;
    best.assign(n + 1, -1e18);
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