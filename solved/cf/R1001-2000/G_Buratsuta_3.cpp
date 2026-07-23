#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

using u64 = uint64_t;

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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, q;
    cin >> n >> q;
    int id = 1;

    gp_hash_table<int, int, custom_hash> mp;
    // mp.reserve(n * 2);
    // mp.max_load_factor(0.7);
    vector<int> mp2;
    vector<vector<int>> pos;
    pos.push_back({}); mp2.push_back(0);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (mp.find(a[i]) == mp.end()) {
            mp[a[i]] = id++;
            pos.push_back({});
            mp2.push_back(a[i]);
        }
        pos[mp[a[i]]].push_back(i);
        mp2[mp[a[i]]] = a[i];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        vector<int> ans;
        for (int i = 0; i < 40; ++i) {
            // if (ans.size() == 2) break;
            int idx = l - 1 + rng() % (r - l + 1);
            int x = mp[a[idx]];  
            auto L = lower_bound(all(pos[x]), l - 1);
            auto R = upper_bound(all(pos[x]), r - 1);
            if (R - L > (r - l + 1) / 3) ans.push_back(mp2[x]);
        }
        // cout << ans.size() << " ";
        if (ans.empty()) ans = {-1};
        sort(all(ans));
        ans.erase(unique(all(ans)), ans.end());
        for (int x : ans) cout << x << " ";
        cout << endl;
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
