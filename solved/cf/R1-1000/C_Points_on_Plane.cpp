#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int S = 1000; 
struct Query {
    int l, r, id;
    bool operator<(Query const& o) const {
        if (l / S != o.l / S) return l < o.l;
        return (l / S & 1) ? (r < o.r) : (r > o.r);
    }
};

const int N = 1e6;
void solve() {
    int q;
    cin >> q;
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--, queries[i].r--;
        queries[i].id = i;
    }
    sort(queries.begin(), queries.end());
    for (int i = 0; i < q; i++) cout << queries[i].id + 1<< " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
