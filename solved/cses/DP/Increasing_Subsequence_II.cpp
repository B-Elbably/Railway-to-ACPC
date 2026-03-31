#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

struct BIT {
    int n;
    vector<int> tree;
    BIT(int n) : n(n), tree(n + 1, 0) {}
    void update(int i, int val) {
        for (; i <= n; i += i & -i) 
            tree[i] = (tree[i] + val) % mod;
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) 
            sum = (sum + tree[i]) % mod;
        return sum;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int m = b.size();
    BIT bit(m);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        int cur = bit.query(pos) + 1;        
        ans += cur; ans %= mod;
        bit.update(pos + 1, cur);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}