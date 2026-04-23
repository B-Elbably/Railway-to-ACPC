#include <bits/stdc++.h>
using namespace std;

using u64 = uint64_t;
using u128 = __int128_t;


struct XorHash {
    vector<u64> pref;
    static u64 splitmix64(u64 x) {
        static const u64 FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x += 0x9e3779b97f4a7c15 + FIXED_RANDOM;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    template<typename T>
    XorHash(const T& a) {
        int n = a.size();
        pref.assign(n + 1, 0);
        set<u64> seen;
        for (int i = 0; i < n; i++) {
            u64 xx = splitmix64(a[i]);
            if (seen.count(xx)) xx = 0;
            pref[i + 1] = pref[i] ^ xx;
            seen.insert(xx);
        }
    }

    u64 get(int l, int r) const {
        return pref[r + 1] ^ pref[l];
    }
};

void solve() {
    int n, q;
    cin >> n;
    vector<long long> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    XorHash h1(a), h2(b);
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        cout << (h1.get(0, l) ^ h2.get(0, r) ? "No" : "Yes") << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}