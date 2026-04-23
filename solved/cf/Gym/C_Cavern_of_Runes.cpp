#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define endl '\n'

long long lcm2(long long x, ll y) {
    if (gcd(x , y) == 0) return 1e18;
    if (y > x) swap(x , y);
    return x / gcd(x, y) * y;
}
void solve() {
    int n;
    cin >> n;
    vector<ll>v;
    // v.push_back(0);
    for (int i=0; i<n; i++) {
        int sz;
        cin >> sz;
        vector<int>p(sz + 2);
        for (int j=1; j<=sz; j++) {
            cin >> p[j];
        }
            // cout << p[j] << " ";
        // }cout << endl;
        vector<int>pre(sz + 2), suf(sz + 2);
        for (int j=1; j<=sz; j++) {
            pre[j] = __gcd(pre[j-1], p[j]);
        }
        for (int j=sz; j>=1; j--) {
            suf[j] = __gcd(suf[j+1], p[j]);
        }
        // for (int j=1; j<=sz; j++) {
        //     cout << pre[j] << " ";
        // }cout << endl;
        // for (int j=sz; j>=1; j--) {
        //     cout << suf[j] << " ";
        // }cout << endl;
        int ans = 0;
        for (int k = 1; k <= sz; ++k) {
            ans = max(ans, __gcd(pre[k - 1], suf[k + 1]));
        }
        // cout << ans << " ";
        // return;
        v.push_back(ans);
    }
    if (n == 1) {
        cout << v[0];
        return;
    }
    // for (int x: v) cout << x << " ";
    vector<long long>pre(n + 2, 1), suf(n + 2, 1);

    for (int j=1; j<=n; j++) {
        pre[j] = lcm2(pre[j-1], v[j - 1]);
    }
    for (int j=n; j>=1; j--) {
        suf[j] = lcm2(suf[j+1], v[j - 1]);
    }
    long long ans = 1e18;
    for (int k = 1; k <= n; ++k) {
        ans = min(ans, lcm2(pre[k - 1], suf[k + 1]));
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}