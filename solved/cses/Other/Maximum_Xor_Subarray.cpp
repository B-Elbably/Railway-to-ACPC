#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int BITS = 31;

struct BinaryTrie {
    struct Node {
        array<int32_t, 2> nxt;
        int32_t cnt = 0;
        Node() { nxt.fill(0); }
    };

    vector<Node> tree;

    BinaryTrie() {
        tree.emplace_back();
    }

    void reserve(int n) {
        tree.reserve(n * (BITS + 1));
    }

    void insert(int x) {
        int u = 0;
        for (int i = BITS; i >= 0; i--) {
            int v = (x >> i) & 1;
            if (!tree[u].nxt[v]) {
                tree[u].nxt[v] = tree.size();
                tree.emplace_back();
            }
            u = tree[u].nxt[v];
            tree[u].cnt++;
        }
    }

    void erase(int x) {
        int u = 0;
        for (int i = BITS; i >= 0; i--) {
            int v = (x >> i) & 1;
            if (!tree[u].nxt[v]) return;
            u = tree[u].nxt[v];
            tree[u].cnt--;
        }
    }

    int get_max(int x) {
        if (tree[0].cnt == 0 && tree.size() <= 1) return 0;
        int u = 0, ans = 0;
        for (int i = BITS; i >= 0; i--) {
            int v = (x >> i) & 1;
            int opp = tree[u].nxt[v ^ 1];
            if (opp && tree[opp].cnt > 0) {
                ans |= (1LL << i);
                u = opp;
            } else {
                u = tree[u].nxt[v];
            }
        }
        return ans;
    }

    int get_min(int x) {
        if (tree[0].cnt == 0 && tree.size() <= 1) return 0;
        int u = 0, ans = 0;
        for (int i = BITS; i >= 0; i--) {
            int v = (x >> i) & 1;
            int same = tree[u].nxt[v];
            if (same && tree[same].cnt > 0) {
                u = same;
            } else {
                ans |= (1LL << i);
                u = tree[u].nxt[v ^ 1];
            }
        }
        return ans;
    }

    int query(int x, int k) {
        int u = 0, ans = 0;
        for (int i = BITS; i >= 0; i--) {
            if (!u) break;
            int v_x = (x >> i) & 1;
            int v_k = (k >> i) & 1;
            if (v_k) {
                int same = tree[u].nxt[v_x];
                if (same) ans += tree[same].cnt;
                u = tree[u].nxt[v_x ^ 1];
            } else {
                u = tree[u].nxt[v_x];
            }
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    BinaryTrie bt;
    bt.insert(0);
    int sum = 0;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum ^= x;
        ans = max(ans, bt.get_max(sum));
        bt.insert(sum);
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
