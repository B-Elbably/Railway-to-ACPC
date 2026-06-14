#include <bits/stdc++.h>
using namespace std;

#define int long long
const int BITS = 30;

struct Node {
    int nxt[2] = {0};
    int cnt = 0;
};

struct BinaryTrie {
    vector<array<int32_t, 2>> nxt;
    vector<int32_t> cnt;
    int sz = 1;
    int elements = 0;

    BinaryTrie(int max_inserts) {
        int max_nodes = max_inserts * (BITS + 1) + 2;
        nxt.assign(max_nodes, {0, 0});
        cnt.assign(max_nodes, 0);
    }

    void insert(int x) {
        int u = 0;
        elements++;
        for (int i = BITS; i >= 0; i--) {
            int v = (x >> i) & 1;
            if (!nxt[u][v]) {
                nxt[u][v] = sz++;
            }
            u = nxt[u][v];
            cnt[u]++;
        }
    }

    void erase(int x) {
        int u = 0;
        elements--;
        for (int i = BITS; i >= 0; i--) {
            int v = (x >> i) & 1;
            if (!nxt[u][v]) return;
            u = nxt[u][v];
            cnt[u]--;
        }
    }

    int get_max(int x) {
        if (elements == 0) return 0;
        int u = 0, ans = 0;
        for (int i = BITS; i >= 0; i--) {
            int v = (x >> i) & 1;
            int opp = nxt[u][v ^ 1];
            if (opp && cnt[opp] > 0) {
                ans |= (1LL << i);
                u = opp;
            } else {
                u = nxt[u][v];
            }
        }
        return ans;
    }

    int get_min(int x) {
        if (elements == 0) return 0;
        int u = 0, ans = 0;
        for (int i = BITS; i >= 0; i--) {
            int v = (x >> i) & 1;
            int same = nxt[u][v];
            if (same && cnt[same] > 0) {
                u = same;
            } else {
                ans |= (1LL << i);
                u = nxt[u][v ^ 1];
            }
        }
        return ans;
    }

    int query(int x, int k) {
        if (elements == 0) return 0;
        int u = 0, ans = 0;
        for (int i = BITS; i >= 0; i--) {
            int v_x = (x >> i) & 1;
            int v_k = (k >> i) & 1;
            
            if (v_k == 1) {
                if (nxt[u][v_x]) {
                    ans += cnt[nxt[u][v_x]];
                }
                if (nxt[u][v_x ^ 1] && cnt[nxt[u][v_x ^ 1]] > 0) {
                    u = nxt[u][v_x ^ 1];
                } else {
                    return ans;
                }
            } else {
                if (nxt[u][v_x] && cnt[nxt[u][v_x]] > 0) {
                    u = nxt[u][v_x];
                } else {
                    return ans;
                }
            }
        }
        return ans;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ans = 0;
    BinaryTrie trie(n + 1);
    trie.insert(0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum ^= a[i];
        ans += i - trie.query(sum, k) + 1;
        trie.insert(sum);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}