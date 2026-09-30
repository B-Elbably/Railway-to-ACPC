    #include <bits/stdc++.h>
    using namespace std;

    #define int long long
    #define all(x) (x).begin(), (x).end()
    #define endl '\n'
    int conv(int n) {
        int sum = 0;
        for (int i = 0; i < 100; i++) {
            sum = 0;
            while (n) {
                int d = n % 10;
                sum += d * d;
                n /= 10;
            }
            n = sum;
        }
        return sum;
    }
    void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> mp;
        for (auto &x : a) cin >> x, x = conv(x), mp[x]++;
        // for (int x: a) cout << x << " ";
        // cout << endl;
        int ans = 0;
        for (auto [x, y] : mp) {
            ans += (y * (y - 1)) / 2;
        }
        cout << ans << endl;
    }

    int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t = 1;
        cin >> t; 
        while (t--) solve();
        return 0;
    }
