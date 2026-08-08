#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl '\n'
const int ALPHABET = 26;
const char START_CHAR = 'a';

struct Trie {
    struct Node {
        array<int32_t, ALPHABET> nxt;
        int32_t cnt = 0;
        int32_t end_cnt = 0;
        Node() { nxt.fill(0); }
    };

    vector<Node> tree;

    Trie() {
        tree.emplace_back();
    }

    void reserve(int n) {
        tree.reserve(n);
    }

    void insert(const string& s) {
        int u = 0;
        for (char c : s) {
            int v = c - START_CHAR;
            if (!tree[u].nxt[v]) {
                tree[u].nxt[v] = tree.size();
                tree.emplace_back();
            }
            u = tree[u].nxt[v];
            tree[u].cnt++;
        }
        tree[u].end_cnt++;
    }

    void erase(const string& s) {
        if (!search(s)) return;
        int u = 0;
        for (char c : s) {
            int v = c - START_CHAR;
            u = tree[u].nxt[v];
            tree[u].cnt--;
        }
        tree[u].end_cnt--;
    }

    bool search(const string& s) {
        int u = 0;
        for (char c : s) {
            int v = c - START_CHAR;
            if (!tree[u].nxt[v]) return false;
            u = tree[u].nxt[v];
        }
        return tree[u].end_cnt > 0;
    }

    int count_prefix(const string& s) {
        int u = 0;
        for (char c : s) {
            int v = c - START_CHAR;
            if (!tree[u].nxt[v]) return 0;
            u = tree[u].nxt[v];
        }
        return tree[u].cnt;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    Trie trie;
    int m = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        trie.insert(s);
        m = max(m, (int)s.length());
    }
    vector<int> ans(m + 1, 0);
    auto dfs = [&](auto self, int u, int d) -> void {
        ans[d] = max(ans[d], trie.tree[u].cnt);
        for (int v : trie.tree[u].nxt) {
            if (v) self(self, v, d + 1);
        }
    };
    dfs(dfs, 0, 0); 
    while (q--) {
        int x; cin >> x;
        cout << ans[x] << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
