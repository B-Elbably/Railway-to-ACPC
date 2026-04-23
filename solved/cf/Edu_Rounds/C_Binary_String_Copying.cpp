#include <bits/stdc++.h>
using namespace std;

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
            base = chrono::steady_clock::now().time_since_epoch().count() % (mod - 100) + 70;
            if (!(base & 1)) base++;
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
};

void solve() {
    int n, m;
    cin >> n >> m;
    string s; cin >> s;
    s = '1' + s + '1';
    Hasher hasher(s);
    Hasher h0(string(n + 2, '0'));
    Hasher h1(string(n + 2, '1'));
    
    vector<int> prefix(n + 2, 0);
    for (int i = 0; i < n + 2; i++) {
        prefix[i] = (s[i] == '1') + (i > 0 ? prefix[i - 1] : 0);
    }
    
    set<u64> ans;
    while (m--) {
        int l, r;
        cin >> l >> r;
        u64 p1 = hasher.get(0, l - 1);
        u64 p3 = hasher.get(r + 1, n + 1);
        
        int c1 = prefix[r] - prefix[l - 1];
        int c0 = (r - l + 1) - c1;
        u64 p2 = c0 > 0 ? h0.get(0, c0 - 1) : 0;
        if (c1 > 0) p2 = hasher.concat(p2, h1.get(0, c1 - 1), c1);
        
        u64 sum = hasher.concat(p1, p2, r - l + 1);
        sum = hasher.concat(sum, p3, n + 1 - r);
        ans.insert(sum);
    }
    cout << ans.size() << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}