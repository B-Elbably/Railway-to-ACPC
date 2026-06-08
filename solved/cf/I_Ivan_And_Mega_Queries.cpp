#include <bits/stdc++.h>
using namespace std;

#define int long long

struct SparseTable {
    int n = 0;
    int K = 0;
    vector<int> lg;
    vector<vector<int>> st;
    function<int(int, int)> merge;

    SparseTable() {}

    SparseTable(const vector<int>& a, function<int(int, int)> op) {
        build(a, op);
    }

    void build(const vector<int>& a, function<int(int, int)> op) {
        merge = op;
        n = (int)a.size();
        if (n == 0) return;

        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;

        K = lg[n] + 1;
        st.assign(K, vector<int>(n));
        for (int i = 0; i < n; ++i) st[0][i] = a[i];

        for (int k = 1; k < K; ++k) {
            int len = 1 << k;
            int half = len >> 1;
            for (int i = 0; i + len <= n; ++i) {
                st[k][i] = merge(st[k - 1][i], st[k - 1][i + half]);
            }
        }
    }

    int query(int l, int r) const {
        int len = r - l + 1;
        int k = lg[len];
        return merge(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    auto op = [](int x, int y) { return max(x, y); };
    SparseTable sp(a, op);

    int q;
    cin >> q;
    while (q--) {
        int m;
        cin >> m;
        vector<int> ind(m);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            cin >> ind[i];
            ans += a[--ind[i]];
        }
        
        if (m > 1) {
            vector<int> M(m - 1);
            for (int i = 0; i < m - 1; i++) {
                M[i] = sp.query(ind[i], ind[i + 1]);
            }
            vector<int> L(m - 1), R(m - 1);
            vector<int> s;
            for (int i = 0; i < m - 1; ++i) {
                while (!s.empty() && M[s.back()] < M[i]) s.pop_back();
                L[i] = s.empty() ? (i + 1) : (i - s.back());
                s.push_back(i);
            }
            s.clear();
            for (int i = m - 2; i >= 0; --i) {
                while (!s.empty() && M[s.back()] <= M[i]) s.pop_back();
                R[i] = s.empty() ? (m - 1 - i) : (s.back() - i);
                s.push_back(i);
            }
            for (int i = 0; i < m - 1; ++i) {
                ans += M[i] * L[i] * R[i];
            }
        }
        cout << ans << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}