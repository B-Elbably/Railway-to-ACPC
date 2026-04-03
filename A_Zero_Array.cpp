#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    unordered_map<int, int, custom_hash> freq;
    for (int i = 0; i < n; i++) cin >> a[i], freq[a[i]]++;

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int idx, val;
            cin >> idx >> val;
            idx--;
            freq[a[idx]]--;
            if (freq[a[idx]] == 0) freq.erase(a[idx]);
            a[idx] = val;
            freq[a[idx]]++;
        }else {
            int ans = freq.size();
            if (freq.count(0)) ans--;
            cout << ans << endl;
            // for (auto &[x, f] : freq) {
            //     cout << x << " " << f << endl;
            // }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
