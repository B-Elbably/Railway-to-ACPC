    #include <bits/stdc++.h>
    using namespace std;

    #define int long long
    #define all(x) (x).begin(), (x).end()
    #define endl '\n'

    void solve() {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        int ans = 0;
        for (int i = 0; i < (1LL << n); ++i) {
            deque<int> b;
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                if (((i >> j) & 1)) b.push_back(a[j]), sum += a[j];
            }
            if (sum < s) continue;
            int bad = 0;
            for (int j = 0; j < (int)b.size(); ++j) {
                if (sum - b[j] >= s) bad = 1;
            }
            if (bad) continue;
            if (sum >= s) ans = max(ans, (int)b.size());
        }
        cout << ans << "\n";
    }

    int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t = 1;
        cin >> t; 
        while (t--) solve();
        return 0;
    }
