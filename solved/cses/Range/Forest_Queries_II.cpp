#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

// 2D
template <typename T>
struct BIT2D {
    int n, m;
    vector<vector<T>> tree;
    
    BIT2D() {}
    BIT2D(int r, int c) {
        init(r, c);
    }
    
    void init(int r, int c) {
        n = r;
        m = c;
        tree.assign(n + 1, vector<T>(m + 1, T()));
    }
    
    void add(int r, int c, T val) {
        for (int i = r + 1; i <= n; i += i & -i) {
            for (int j = c + 1; j <= m; j += j & -j) {
                tree[i][j] += val;
            }
        }
    }
    
    T query(int r, int c) const {
        T res = T();
        for (int i = r + 1; i > 0; i -= i & -i) {
            for (int j = c + 1; j > 0; j -= j & -j) {
                res += tree[i][j];
            }
        }
        return res;
    }
    
    T query(int r1, int c1, int r2, int c2) const {
        if (r1 > r2 || c1 > c2) return T();
        return query(r2, c2) - query(r1 - 1, c2) - query(r2, c1 - 1) + query(r1 - 1, c1 - 1);
    }
};


void solve() {
    int n, q;
    cin >> n >> q;
    BIT2D<int> bit(n, n);
    char c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c;
            if (c == '*') {
                bit.add(i, j, 1);
            }
        }
    }  
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            --x, --y;
            int val = bit.query(x, y, x, y);
            if (val == 0) {
                bit.add(x, y, 1);
            } else {
                bit.add(x, y, -1);
            }
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            --x1, --y1, --x2, --y2;
            cout << bit.query(x1, y1, x2, y2) << endl;
        }
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
