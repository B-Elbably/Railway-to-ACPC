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
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + splitmix64(a[i]);
    }

    u64 get(int l, int r) const {
        return pref[r + 1] - pref[l];
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
    int n;
    cin >> n;
    vector<u64> a(n + 2);
    for (int i = 1; i <= n; ++i) {
        u64 u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        a[i] = (u << 32) | v;
    }
    XorHash h(a);
    int ans = 0;
    unordered_map<u64, int, custom_hash> freq;
    freq.reserve(1 << 21);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            freq[h.get(i, j)]++;
        }
    }
    for (auto& [_, v] : freq) {
        ans += v * (v - 1) / 2;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}