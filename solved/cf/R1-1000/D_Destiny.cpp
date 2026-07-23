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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
uint64_t seed = chrono::steady_clock::now().time_since_epoch().count();
inline uint64_t rng() {
    seed += 0x9e3779b97f4a7c15;
    uint64_t z = seed;
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
    z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
    return z ^ (z >> 31);
}
void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> pos(n + 1, vector<int>());
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    vector<int> seen(n + 1, 0);
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        int ans = LLONG_MAX;
        int target = (r - l + 1) / k;
        vector<int> saw;
        for (int i = 0; i < 70; ++i) { 
            int idx = l - 1 + rng() % (r - l + 1);
            if (seen[a[idx]]) continue;
            seen[a[idx]] = 1;
            saw.push_back(a[idx]);
            const auto &v = pos[a[idx]];
            if ((int)v.size() <= target) continue;
            auto it1 = lower_bound(v.begin(), v.end(), l - 1);
            auto it2 = upper_bound(v.begin(), v.end(), r - 1);
            int cnt = it2 - it1;
            if (cnt > target) ans = min(ans, a[idx]);
        }
        for (int x : saw) seen[x] = 0;
        if (ans == LLONG_MAX) ans = -1;
        cout << ans << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
