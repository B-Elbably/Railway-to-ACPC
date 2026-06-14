#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int ALPHABET = 26;
const char START_CHAR = 'a';

struct Trie {
    vector<array<int32_t, ALPHABET>> nxt;
    vector<int32_t> cnt;
    vector<int32_t> end_cnt;
    int32_t node_cnt = 1;

    Trie(int max_nodes) {
        nxt.assign(max_nodes + 2, {0});
        cnt.assign(max_nodes + 2, 0);
        end_cnt.assign(max_nodes + 2, 0);
    }

    void insert(const string& s) {
        int u = 0;
        for (char c : s) {
            int v = c - START_CHAR;
            if (!nxt[u][v]) nxt[u][v] = node_cnt++;
            u = nxt[u][v];
            cnt[u]++;
        }
        end_cnt[u]++;
    }

    void erase(const string& s) {
        int u = 0;
        for (char c : s) {
            int v = c - START_CHAR;
            if (!nxt[u][v]) return;
            u = nxt[u][v];
            cnt[u]--;
        }
        end_cnt[u]--;
    }

    bool search(const string& s) {
        int u = 0;
        for (char c : s) {
            int v = c - START_CHAR;
            if (!nxt[u][v]) return false;
            u = nxt[u][v];
        }
        return end_cnt[u] > 0;
    }

    int count_prefix(const string& s) {
        int u = 0;
        for (char c : s) {
            int v = c - START_CHAR;
            if (!nxt[u][v]) return 0;
            u = nxt[u][v];
        }
        return cnt[u];
    }
};
const int MOD = 1e9 + 7;
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int k;
    cin >> k;
    Trie trie(1000000); 
    for (int i = 0; i < k; i++) {
        string word;
        cin >> word;
        trie.insert(word);
    }

    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        int u = 0;
        for (int j = i; j < n; j++) {
            int v = s[j] - 'a';
            if (!trie.nxt[u][v]) break; 
            u = trie.nxt[u][v];
            if (trie.end_cnt[u]) {
                dp[i] = (dp[i] + dp[j + 1]) % MOD;
            }
        }
    }
    cout << dp[0] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}