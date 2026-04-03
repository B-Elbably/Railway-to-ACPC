#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> a;
vector<int> freq;
vector<int> ans;
const int N = 2e5 + 5;
int SQ;
vector<int> freqB;
// set<int> mex; 

void add(int x) {
    // if (x >= N) return;
    if (freq[x]++ == 0) freqB[x / SQ]++;
    // freq[x]++;
}

void remove_(int x) {
    // if (x >= N) return;
    // freq[x]--;
    if (--freq[x] == 0) freqB[x / SQ]--;
}

struct Query {
    int l, r, idx;
    bool operator<(const Query &other) const {
        if (l / SQ != other.l / SQ)
            return l / SQ < other.l / SQ;
        return r < other.r;
    }
};

void solve() {
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    SQ = sqrt(N) + 5;
    freqB.resize(SQ + 5, 0);
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--, queries[i].r--;
        queries[i].idx = i;
    }
    sort(queries.begin(), queries.end());

    freq.assign(N + 2, 0);
    ans.resize(q);
    freq[0]++;
    freqB[0]++;
    int l = 0, r = -1;
    for (auto &qr : queries) {
        while (l > qr.l) add(a[--l]);
        while (r < qr.r) add(a[++r]);
        while (l < qr.l) remove_(a[l++]);
        while (r > qr.r) remove_(a[r--]);
        bool ok = true;
        for (int i = 0; i <= SQ && ok; ++i) {
            if (freqB[i] == SQ) continue;
            for (int j = i * SQ; j < (i + 1) * SQ; ++j) {
                if (freq[j]) continue;
                ans[qr.idx] = j; ok = false;
                break;
            }   
        }
    }

    for (auto &x : ans) cout << x << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}