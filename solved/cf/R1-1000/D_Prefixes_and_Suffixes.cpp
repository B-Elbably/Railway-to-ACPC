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
        u64 res = pref[r + 1] - fast_mod((u128)pref[l] * pw[r - l + 1]);
        return (int64_t)res < 0 ? res + mod : res;
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

const int N = 1e5 + 5;
int pi[N];
void KMP (const string &s) {
    int n = s.size();
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
}

void solve() {
    string s; cin >> s;
    int n = s.size();
    Hasher dh(s);
    KMP(s);
    map<int, int> cnt;
    for (int i =0; i < n; ++i) {
        cnt[pi[i]]++;
    }
    for (int i = n; i > 0; i--) {
        cnt[pi[i - 1]] += cnt[i];
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        if (dh.get(0, i) == dh.get(n - i - 1, n - 1)) {
            // cout << i + 1 << " " << cnt[i] + 1 << endl;
            ans.emplace_back(i + 1, ++cnt[i + 1]);
        }
    }
    cout << ans.size() << endl;
    for (auto &[i, j] : ans) {
        cout << i << " " << j << endl;
    }
    // cout << n << " " << 1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
