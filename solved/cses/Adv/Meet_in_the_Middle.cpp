#include <bits/stdc++.h>
using namespace std;
 
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
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int m = n / 2;
    vector<int> left, right;
    for (int i = 0; i < (1 << m); i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) sum += a[j];
        }
        left.push_back(sum);
    }
    for (int i = 0; i < (1 << (n - m)); i++) {
        int sum = 0;
        for (int j = 0; j < n - m; j++) {
            if (i & (1 << j)) sum += a[j + m];
        }
        right.push_back(sum);
    }
    sort(all(right));
    int ans = 0;
    for (int s : left) {
        auto res = equal_range(all(right), x - s);
        ans += distance(res.first, res.second);
    }
    cout << ans << endl;
 
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}