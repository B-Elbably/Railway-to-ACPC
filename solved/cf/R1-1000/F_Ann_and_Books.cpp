#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int S = 320; 

struct Query {
    int l, r, id;
    bool operator<(Query const& o) const {
        if (l / S != o.l / S) return l / S < o.l / S;
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


vector<int> a, pref, t;
int n, k;
gp_hash_table<int, int, custom_hash> diff;
int ans = 0;

inline void add_right(int idx) {
    ans += diff[pref[idx] - k];
    diff[pref[idx]]++;
}

inline void remove_right(int idx) {
    ans -= diff[pref[idx] - k] - (k == 0);
    diff[pref[idx]]--;
}

inline void add_left(int idx) {
    ans += diff[pref[idx] + k];
    diff[pref[idx]]++;
}

inline void remove_left(int idx) {
    ans -= diff[pref[idx] + k] - (k == 0);
    diff[pref[idx]]--;
}

vector<int> mo_algorithm(vector<Query>& queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());
    int curr_l = 0;
    int curr_r = -1;
    for (const Query &q : queries) {
        while (curr_l > q.l) add_left(--curr_l);
        while (curr_r < q.r) add_right(++curr_r);
        while (curr_l < q.l) remove_left(curr_l++);
        while (curr_r > q.r) remove_right(curr_r--);
        answers[q.id] = ans;
    }
    return answers;
}

void solve() {
    // diff.reserve(1 << 18);
    cin >> n >> k;
    a.resize(n); t.resize(n);
    pref.resize(n + 1);
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        int x = (t[i] == 1 ? a[i] : -a[i]);
        pref[i + 1] = pref[i] + x;
    }
    int q;
    cin >> q;
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--, 
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
