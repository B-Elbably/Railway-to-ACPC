#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct Query {
    int id, k, rem, idx;
};

bool compareQueries(const Query& a, const Query& b) {
    return a.idx < b.idx;
}

int bit[500005];
int M;

void update(int i, int delta) {
    for (; i <= M; i += i & -i) bit[i] += delta;
}

int find_kth(int k) {
    int idx = 0;
    for (int i = 1 << 19; i > 0; i >>= 1) {
        if (idx + i <= M && bit[idx + i] < k) {
            idx += i;
            k -= bit[idx];
        }
    }
    return idx + 1;
}

void solve() {
    int n, m, q;
    if (!(cin >> n >> m >> q)) return;
    M = m;

    vector<int> cnt(m + 1, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    vector<pair<int, int>> freq;
    for (int i = 1; i <= m; i++) freq.push_back({cnt[i], i});
    sort(freq.begin(), freq.end());

    vector<int> pref(m + 1, 0);
    for (int i = 1; i < m; i++) {
        pref[i] = pref[i-1] + i * (freq[i].first - freq[i-1].first);
    }

    vector<Query> qs(q);
    vector<int> answers(q);
    for (int i = 0; i < q; i++) {
        int k; cin >> k;
        k -= n;
        qs[i].id = i;
        if (k > pref[m-1]) {
            qs[i].idx = m;
            qs[i].rem = (k - pref[m-1] - 1) % m + 1;
        } else {
            int idx = lower_bound(pref.begin(), pref.begin() + m, k) - pref.begin();
            qs[i].idx = idx;
            qs[i].rem = (k - pref[idx-1] - 1) % idx + 1;
        }
    }

    sort(qs.begin(), qs.end(), compareQueries);

    int cur_idx = 0;
    for (auto &query : qs) {
        while (cur_idx < query.idx) {
            update(freq[cur_idx].second, 1);
            cur_idx++;
        }
        answers[query.id] = find_kth(query.rem);
    }

    for (int x : answers) cout << x << endl;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}