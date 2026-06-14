#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int BITS = 30;

struct Node {
    int nxt[2] = {0};
    int cnt = 0;
};

struct BinaryTrie {
    vector<Node> nodes;

    BinaryTrie() {
        nodes.emplace_back();
    }

    void insert(int x) {
        int u = 0;
        for (int i = BITS; i >= 0; i--) {
            int v = (x >> i) & 1;
            if (!nodes[u].nxt[v]) {
                nodes[u].nxt[v] = nodes.size();
                nodes.emplace_back();
            }
            u = nodes[u].nxt[v];
            nodes[u].cnt++;
        }
    }

    void erase(int x) {
        int u = 0;
        for (int i = BITS; i >= 0; i--) {
            int v = (x >> i) & 1;
            if (!nodes[u].nxt[v]) return;
            u = nodes[u].nxt[v];
            nodes[u].cnt--;
        }
    }

    int get_max_xor(int x) {
        int u = 0, ans = 0;
        for (int i = BITS; i >= 0; i--) {
            int v = (x >> i) & 1;
            int opp = nodes[u].nxt[v ^ 1];
            if (opp && nodes[opp].cnt > 0) {
                ans |= (1LL << i);
                u = opp;
            } else {
                u = nodes[u].nxt[v];
            }
        }
        return ans;
    }
};

void solve() {
    int q;
    cin >> q;
    BinaryTrie trie;
    trie.insert(0);
    while (q--) {
        char t;
        int x;
        cin >> t >> x;
        if (t == '+') {
            trie.insert(x);
        } else if (t == '-') {
            trie.erase(x);
        } else {
            cout << trie.get_max_xor(x) << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}