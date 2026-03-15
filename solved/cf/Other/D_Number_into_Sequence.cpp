#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

vector<int> factorize(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

void solve() {
    int n;
    cin >> n;
    vector<int> factors = factorize(n);
    // sort(all(factors));
    map<int, int> freq;
    for (int x : factors) freq[x]++;
    int cnt = 0;
    int mx = 0;
    for (auto &[k, v] : freq) {
        if (v > cnt) {
            cnt = v;
            mx = k;
        }
    }
    vector<int> ans;
    for (int i = 0; i < cnt - 1; i++) ans.push_back(mx);
    int m = mx;
    for (int x : factors) {
        if (x != mx) m *= x;
    }
    ans.push_back(m);
    cout << ans.size() << endl;
    sort(all(ans));
    for (auto &x : ans) cout << x << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}