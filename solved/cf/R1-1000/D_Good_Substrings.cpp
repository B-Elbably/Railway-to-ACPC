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

struct custom_hash {
    static u64 splitmix64(u64 x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(u64 x) const {
        static const u64 FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    template<typename T, typename U>
    size_t operator()(const pair<T, U>& p) const {
        u64 h1 = (*this)(p.first);
        u64 h2 = (*this)(p.second);
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};

void solve() {
    string s; cin >> s;
    int n = s.size();
    string good; cin >> good;
    int k; cin >> k;
    Hasher dh(s);
    unordered_set<u64, custom_hash> seen;
    seen.reserve(1 << 20);
    seen.max_load_factor(0.25);

    for (int i = 0; i < n; i++) {
        int bad = 0;
        for (int j = i; j < n; j++) {
            if (good[s[j] - 'a'] == '0') bad++;
            if (bad > k) break;
            seen.insert(dh.get(i, j));
        }
    }
    cout << seen.size() << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
