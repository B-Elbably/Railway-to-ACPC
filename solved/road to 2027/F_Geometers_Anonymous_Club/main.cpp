#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct Query {
    int l, id;
};
const int N = 1e5 + 5;
int bit[N];
int n;

void add(int idx, int val) {
    for (; idx <= n; idx += idx & -idx) {
        bit[idx] += val;
    }
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

// the number of vertices in the sum of Minkowski of polygons with indices [l, r];

void solve() {
    cin >> n;
    vector<vector<pair<int, int>>> polys(n + 1);
    vector<pair<int, int>> all_dirs;
    // all polys are CCW;
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        vector<pair<int, int>> pts(k);
        for (int j = 0; j < k; ++j) {
            cin >> pts[j].first >> pts[j].second;
        }
        for (int j = 0; j < k; ++j) {
            int dx = pts[(j + 1) % k].first - pts[j].first;
            int dy = pts[(j + 1) % k].second - pts[j].second;
            int g = __gcd(abs(dx), abs(dy));
            dx /= g;
            dy /= g;
            polys[i].push_back({dx, dy});
            all_dirs.push_back({dx, dy});
        }
    }
    
    sort(all(all_dirs));
    all_dirs.erase(unique(all(all_dirs)), all_dirs.end());
    vector<vector<int>> polys_id(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (auto& dir : polys[i]) {
            int id = lower_bound(all(all_dirs), dir) - all_dirs.begin() + 1;
            polys_id[i].push_back(id);
        }
    }
    
    int q;
    cin >> q;
    vector<vector<Query>> queries(n + 1);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        queries[r].push_back({l, i});
    }
    
    vector<int> ans(q);
    vector<int> seen(all_dirs.size() + 1, 0);
    
    for (int r = 1; r <= n; ++r) {
        for (int id : polys_id[r]) {
            if (seen[id] != 0) {
                add(seen[id], -1);
            }
            seen[id] = r;
            add(r, 1);
        }
        
        for (auto& qry : queries[r]) {
            ans[qry.id] = query(r) - query(qry.l - 1);
        }
    }
    
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}