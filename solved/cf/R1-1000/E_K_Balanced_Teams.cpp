#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
vector<int> a;
const int N = 5e3 + 5;
int memo[N][N];
int n, k;

int go(int i, int K) {
    if (i > n || K == 0) return 0;
    int &ret = memo[i][K];
    if (~ret) return ret;
    ret = go(i + 1, K);
    int j = i;
    while (j <= n && a[j] - a[i] <= 5) {
        j++;
    }
    ret = max(ret, (j - i) + go(j, K - 1));
    return ret;
}

void solve() {
    cin >> n >> k;
    a.resize(n + 1);
    memset(memo, -1, sizeof(memo));
    for (int i = 1; i <= n; i++) { cin >> a[i]; }
    sort(all(a));
    // for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    cout << go(1, k) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
