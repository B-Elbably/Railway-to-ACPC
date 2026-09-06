#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int BLOCK = 450;
 
struct Query {
    int l, r, id;
    bool operator<(const Query& o) const {
        int b1 = l / BLOCK, b2 = o.l / BLOCK;
        if (b1 != b2) return b1 < b2;
        return (b1 & 1) ? r < o.r : r > o.r;
    }
};
 
int freq[200005];
int res = 0;
void add(int x) {
    if (++freq[x] == 1) res++;
}
void remove(int x) {
    if (--freq[x] == 0) res--;
}
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), vals(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        vals[i - 1] = a[i];
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    }
    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].id = i;
    }
 
    sort(queries.begin(), queries.end());
    vector<int> ans(q);
    int L = 1, R = 0;
    for (const auto& qry : queries) {
        while (L > qry.l) add(a[--L]);
        while (R < qry.r) add(a[++R]);
        while (L < qry.l) remove(a[L++]);
        while (R > qry.r) remove(a[R--]);
        ans[qry.id] = res;
    }
 
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << "\n";
    }
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    // cin >> t; 
    while (t--) solve();
}