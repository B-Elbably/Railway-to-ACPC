#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

vector<int> spf(N + 1);
int freq[N + 1];
ll inv[N + 1];
ll add_val[N + 1];
ll rem_val[N + 1];
int S;

struct Query {
    int l, r, id;
    bool operator<(Query const& o) const {
        if (l / S != o.l / S)
            return l / S < o.l / S;
        return ((l / S) & 1) ? r > o.r : r < o.r;
    }
};

vector<int> a;
vector<vector<int>> factors;
ll ans = 1;

void build() {
    inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    }
    for (int i = 2; i <= N; i++) {
        add_val[i] = (i - 1) * inv[i] % MOD;
        rem_val[i] = i * inv[i - 1] % MOD;
    }
    for (int i = 0; i <= N; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

inline void add(int idx) {
    ans = ans * a[idx] % MOD;
    for (int p : factors[idx]) {
        if (!freq[p]) {
            ans = ans * add_val[p] % MOD;
        }
        freq[p]++;
    }
}

inline void remove(int idx) {
    ans = ans * inv[a[idx]] % MOD;
    for (int p : factors[idx]) {
        freq[p]--;
        if (!freq[p]) {
            ans = ans * rem_val[p] % MOD;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    a.resize(n);
    factors.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int y = a[i];
        while (y > 1) {
            int p = spf[y];
            factors[i].push_back(p);
            while (y % p == 0) y /= p;
        }
    }
    
    int q; 
    cin >> q;
    S = max(1, (int)(n / sqrt(q)));
    vector<Query> queries(q);
    
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].id = i;
        queries[i].l--, queries[i].r--;
    }
    
    sort(queries.begin(), queries.end());
    vector<int> answers(queries.size());
    int curr_l = 0;
    int curr_r = -1;
    
    for (const Query &q : queries) {
        while (curr_l > q.l) add(--curr_l);
        while (curr_r < q.r) add(++curr_r);
        while (curr_l < q.l) remove(curr_l++);
        while (curr_r > q.r) remove(curr_r--);
        answers[q.id] = ans;
    }
    
    for (int x : answers) cout << x << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    int t = 1;
    while (t--) solve();
    return 0;
}