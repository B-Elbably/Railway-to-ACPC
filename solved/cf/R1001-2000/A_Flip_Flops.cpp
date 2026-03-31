    #include <bits/stdc++.h>
    using namespace std;

    #define int long long
    #define all(x) (x).begin(), (x).end()
    #define endl '\n'

    void solve() {
        int n, c, k;
        cin >> n >> c >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(all(a));
        for (int i = 0; i < n; ++i) {
            if (a[i] > c) break;
            int diff = min(c - a[i], k);
            int ai = a[i] + diff;
            k -= diff;
            c += ai;
        }
        cout << c << endl;
    }

    int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t = 1;
        cin >> t; 
        while (t--) solve();
    }
