#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int MAXN = 1e6 + 5;
int spf[MAXN];

void sieve() {
    for (int i = 1; i < MAXN; ++i) spf[i] = i;
    for (int i = 2; i * i < MAXN; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

set<int> factorize(int x) {
    set<int> factors;
    while (x > 1) {
        factors.insert(spf[x]);
        x /= spf[x];
    }
    return factors;
}

void solve() {
    sieve();
    int n;
    cin >> n;
    map<set<int>, int> ans;
    vector<int> a(n);
    int ok = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            ok = 1; continue;
        }
        ans[factorize(a[i])]++;
    }
    cout << ans.size() + ok << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
