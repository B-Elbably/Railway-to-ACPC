#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int S = 320; 

struct Query {
    int l, r, id;
    bool operator<(Query const& o) const {
        if (l / S != o.l / S) return l < o.l;
        return (l / S & 1) ? (r < o.r) : (r > o.r);
    }
};


using u64 = uint64_t;

struct custom_hash {
    static u64 splitmix64(u64 x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(u64 x) const {
        static const u64 FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    template<typename T, typename U>
    size_t operator()(const pair<T, U>& p) const {
        u64 h1 = (*this)(p.first);
        u64 h2 = (*this)(p.second);
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};

const int N = 1e5 + 5;
vector<int> a;
int freq[N];
int ans = 0;

inline void add(int idx) {
    if (a[idx] >= N) return;
    freq[a[idx]]++;
    if (freq[a[idx]] == a[idx]) ans++;
    if (freq[a[idx]] == a[idx] + 1) ans--;
}

inline void remove(int idx) {
    if (a[idx] >= N) return;
    freq[a[idx]]--;
    if (freq[a[idx]] == a[idx]) ans++;
    if (freq[a[idx]] == a[idx] - 1) ans--;
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
