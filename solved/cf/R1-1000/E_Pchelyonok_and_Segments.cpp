#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e5 + 5;
const int SQ = 450;
vector<int> a, pref;
int memo[SQ][N];
int n;

const int INF = 1e18;
int dp(int i, int len) {
    if (len == 0) return INF;
    if (i + len > n) return -INF;
    int &ret = memo[len][i];
    if (~ret) return ret;
    ret = dp(i + 1, len);
    int sum = pref[i + len] - pref[i];
    int op2 = dp(i + len, len - 1);
    if (op2 != -INF && sum < op2)
        ret = max(ret, sum);
    return ret;
}

void solve() {
    cin >> n;
    a.resize(n);
    pref.resize(n + 1);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < n; ++i) 
        pref[i + 1] = pref[i] + a[i];
    int ans = 0;
    while (++ans) {
        fill(memo[ans], memo[ans] + n + 1, -1);
        if (dp(0, ans) == -INF) break;
    }
    cout << --ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
