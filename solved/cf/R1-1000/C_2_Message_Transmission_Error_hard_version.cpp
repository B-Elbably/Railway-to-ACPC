#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using u64 = uint64_t;
using u128 = __int128_t;

struct Hasher {
    static inline u64 base = 0;
    static const u64 mod = (1ULL << 61) - 1;
    const string &s;
    vector<u64> pref, pw;

    static u64 fast_mod(u128 x) {
        u64 res = (u64)(x >> 61) + (u64)(x & mod);
        return res >= mod ? res - mod : res;
    }

    Hasher(const string& str) : s(str) {
        if (!base) {
            base = 911382323;
        }
        int n = s.size();
        pref.assign(n + 1, 0);
        pw.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = fast_mod((u128)pref[i] * base + s[i]);
            pw[i + 1] = fast_mod((u128)pw[i] * base);
        }
    }

    u64 get(int l, int r) const {
        if (l > r) return 0;
        u64 res = pref[r + 1] - fast_mod((u128)pref[l] * pw[r - l + 1]);
        return (int64_t)res < 0 ? res + mod : res;
    }

    u64 concat(u64 left_hash, u64 right_hash, int right_len) const {
        if (right_len == 0) return left_hash;
        return fast_mod((u128)left_hash * pw[right_len] + right_hash);
    }

    bool is_less(int l1, int r1, int l2, int r2) const {
        int n1 = r1 - l1 + 1, n2 = r2 - l2 + 1;
        int low = 1, high = min(n1, n2), lcp = 0;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (get(l1, l1 + mid - 1) == get(l2, l2 + mid - 1)) {
                lcp = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return lcp == min(n1, n2) ? n1 < n2 : s[l1 + lcp] < s[l2 + lcp];
    }
};

const int N = 4e5 + 15;
int pi[N];
void KMP(const string &s) {
    int n = s.size();
    for (int i = 0; i < n; i++) pi[i] = 0;
    
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
}

int aut[N][26];
void automaton(const string &s) {
    int n = s.size();
    KMP(s);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 26; j++) aut[i][j] = 0;
    }

    aut[0][s[0] - 'a'] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            if (i < n && s[i] - 'a' == j) {
                aut[i][j] = i + 1;
            } else {
                aut[i][j] = aut[pi[i - 1]][j];
            }
        }
    }
}

void solve() {
    string s;
    cin >> s;
    // s = s + '#' + s;
    KMP(s);
    int n = s.size();
    int j = pi[n - 1];
    vector<int> ans;
    while (j > 0) {
        ans.push_back(j);
        j = pi[j - 1];
    }
    reverse(all(ans));
    Hasher h(s);
    // cout << ans.size() << endl;
    for (int i : ans) {
        if (i < (n + 2) / 2) continue;
        int op1 = h.get(0, i - 1);
        int op2 = h.get(n - i, n - 1);
        if (op1 == op2) {
            cout << "YES" << endl;
            for (int j = 0; j < i; j++) cout << s[j];
            cout << endl;
            return;
        }
    }
    cout << "NO" << endl;
    // cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
