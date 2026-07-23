#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int S = 320; 

struct Query {
    int l, r, id;
    bool operator<(Query const& o) const {
        if (l / S != o.l / S)
            return l / S < o.l / S;
        return ((l / S) & 1) ? r > o.r : r < o.r;
    }
};


vector<int> a;
int ans = 0;

inline void add(int idx) {

}

inline void remove(int idx) {
    
}

vector<int> mo_algorithm(vector<Query>& queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    int curr_l = 0;
    int curr_r = -1;

    for (Query q : queries) {
        while (curr_l > q.l) add(--curr_l);
        while (curr_r < q.r) add(++curr_r);
        while (curr_l < q.l) remove(curr_l++);
        while (curr_r > q.r) remove(curr_r--);
        answers[q.id] = ans;
    }
    return answers;
}

void solve() {
    int n, q;
    cin >> n >> q;
    a.resize(n);
    for (auto &x : a) cin >> x;
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--, queries[i].r--;
        queries[i].id = i;
    }
    vector<int> answers = mo_algorithm(queries);
    for (int x : answers) cout << x << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
