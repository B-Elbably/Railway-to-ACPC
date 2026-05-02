#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int LOGA = 31;
int BLOCK;
vector<int> a;
vector<long long> ans;
int freq[N * LOGA]; // Use array for O(1) instead of map
long long res = 0;

// Precomputed transitions: {compressed_value, index_where_it_starts/ends}
vector<pair<int, int>> fwd[N], bck[N];
int curL = 0, curR = -1;

struct Query {
    int lx, rx, idx;
    bool operator<(const Query &other) const {
        int b1 = lx / BLOCK, b2 = other.lx / BLOCK;
        if (b1 != b2) return b1 < b2;
        return (b1 & 1) ? (rx < other.rx) : (rx > other.rx);
    }
};

void add(int pos) {
    if (pos == curL) { // Pointer moved left: check subarrays starting at 'pos'
        for (auto &p : fwd[pos]) {
            if (p.second <= curR) {
                if (++freq[p.first] == 1) res++;
            } else break;
        }
    } else { // Pointer moved right: check subarrays ending at 'pos'
        for (auto &p : bck[pos]) {
            if (p.second >= curL) {
                if (++freq[p.first] == 1) res++;
            } else break;
        }
    }
}

void remove_(int pos) {
    if (pos == curL) {
        for (auto &p : fwd[pos]) {
            if (p.second <= curR) {
                if (--freq[p.first] == 0) res--;
            } else break;
        }
    } else {
        for (auto &p : bck[pos]) {
            if (p.second >= curL) {
                if (--freq[p.first] == 0) res--;
            } else break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    BLOCK = max(1.0, (double)n / sqrt(q + 1));
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // Precompute transitions and collect all distinct OR values for compression
    vector<int> all_ors;
    vector<pair<int, int>> curr;
    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> next_v;
        next_v.push_back({a[i], i});
        for (auto &p : curr) {
            int val = p.first | a[i];
            if (val != next_v.back().first) next_v.push_back({val, p.second});
            else next_v.back().second = p.second;
        }
        bck[i] = next_v;
        for (auto &p : next_v) all_ors.push_back(p.first);
        curr = next_v;
    }

    curr.clear();
    for (int i = n - 1; i >= 0; i--) {
        vector<pair<int, int>> next_v;
        next_v.push_back({a[i], i});
        for (auto &p : curr) {
            int val = p.first | a[i];
            if (val != next_v.back().first) next_v.push_back({val, p.second});
            else next_v.back().second = p.second;
        }
        fwd[i] = next_v;
        curr = next_v;
    }

    sort(all_ors.begin(), all_ors.end());
    all_ors.erase(unique(all_ors.begin(), all_ors.end()), all_ors.end());

    auto get_id = [&](int val) {
        return lower_bound(all_ors.begin(), all_ors.end(), val) - all_ors.begin();
    };

    for (int i = 0; i < n; i++) {
        for (auto &p : fwd[i]) p.first = get_id(p.first);
        for (auto &p : bck[i]) p.first = get_id(p.first);
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = {l - 1, r - 1, i};
    }

    sort(queries.begin(), queries.end());
    ans.resize(q);

    for (auto &qry : queries) {
        int L = qry.lx, R = qry.rx;
        while (curL > L) add(--curL);
        while (curR < R) add(++curR);
        while (curL < L) remove_(curL++);
        while (curR > R) remove_(curR--);
        ans[qry.idx] = res;
    }

    for (auto x : ans) cout << x << '\n';
    return 0;
}