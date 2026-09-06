#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 2e6 + 5;
const int shift = 1e6 + 2;
struct segmentTree {
    int n;
    vector<int> cov, len;

    segmentTree(int n) : n(n), cov(4 * n, 0), len(4 * n, 0) {}

    void update(int node, int start, int end, int l, int r, int val) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            cov[node] += val;
        } else {
            int mid = start + (end - start) / 2;
            update(2 * node, start, mid, l, r, val);
            update(2 * node + 1, mid + 1, end, l, r, val);
        }
        if (cov[node] > 0) {
            len[node] = end - start + 1;
        } else {
            len[node] = (start == end) ? 0 : len[2 * node] + len[2 * node + 1];
        }
    }

    void update(int l, int r, int val) {
        update(1, 0, n - 1, l, r, val);
    }

    int query(int l, int r) {
        return len[1];
    }
};

struct line {
    int x, y1, y2, type;
    bool operator<(const line& other) const {
        if (x != other.x)
            return x < other.x;
        return type < other.type;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<line> lines;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += shift; x2 += shift;
        y1 += shift; y2 += shift;
        lines.push_back({min(x1, x2), min(y1, y2), max(y1, y2) - 1, 1});
        lines.push_back({max(x1, x2), min(y1, y2), max(y1, y2) - 1, 2});
    }
    sort(all(lines));
    int ans = 0;
    segmentTree seg(N);
    for (int i = 0; i < 2 * n; ++i) {
        const auto& l = lines[i];
        if (i)
            ans += seg.query(0, N - 1) * (l.x - lines[i - 1].x);
        if (l.type == 1) {
            seg.update(l.y1, l.y2, 1);
        } else {
            seg.update(l.y1, l.y2, -1);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
