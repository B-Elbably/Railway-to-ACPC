// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n;
vector<int> a;
const int N = 1e5 + 5;
deque<int> freq[N];
int sum[N], cnt[N];
const int S = 320; 
int mn;

struct Query {
    int l, r, id;
    bool operator<(Query const& o) const {
        if (l / S != o.l / S)
            return l / S < o.l / S;
        return ((l / S) & 1) ? r > o.r : r < o.r;
    }
};

int ans = 0;
inline void add(int idx) {
    int sz = freq[a[idx]].size();
    if (sz && idx > freq[a[idx]].back()) {
        int gap = idx - freq[a[idx]].back() - 1; 
        sum[a[idx]] += gap * (gap + 1) / 2;   
        freq[a[idx]].push_back(idx);
    } else {
        if (sz) {        
            int gap = freq[a[idx]].front() - idx - 1;
            sum[a[idx]] += gap * (gap + 1) / 2;   
        }  
        freq[a[idx]].push_front(idx);
    }
    mn = min(mn, a[idx]);
    cnt[a[idx]]++;
}

inline void remove(int idx) {
    int sz = freq[a[idx]].size();
    if (sz && idx == freq[a[idx]].back()) {
        freq[a[idx]].pop_back();
        if (!freq[a[idx]].empty()) {
            int gap = idx - freq[a[idx]].back() - 1; 
            sum[a[idx]] -= gap * (gap + 1) / 2;   
        }
        
    } else {
        freq[a[idx]].pop_front();
        if (!freq[a[idx]].empty()) {
            int gap = freq[a[idx]].front() - idx - 1;
            sum[a[idx]] -= gap * (gap + 1) / 2;   
        }
    }
    cnt[a[idx]]--;
    if (freq[a[idx]].empty()) {
        cnt[a[idx]] = 0;
        while (cnt[mn] == 0) mn++;
    }
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
        // int mn = freq.begin()->first;
        int &ans = answers[q.id];
        int sz = q.r - q.l + 1;
        ans = sz * (sz + 1) / 2;
        int left = freq[mn].front() - q.l;
        int right = q.r - freq[mn].back();
        ans -= left * (left + 1) / 2;
        ans -= right * (right + 1) / 2;
        ans -= sum[mn];
        ans -= (left + 1) * (right + 1); 
    }
    return answers;
}

void solve() {
    cin >> n;
    a.resize(n);
    mn = n + 1;
    for (auto &x : a) cin >> x;
    vector<int> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for (auto &x : a) {
        x = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
    }

    int q;
    cin >> q;
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
