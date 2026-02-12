// NOTE: too much (r value) -> WA cause of overflow;
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

struct worker {
    int time, count, break_; 
};

void solve() {
    int n, m; cin >> m >> n;
    vector<worker> a(n);
    for (auto &x : a) cin >> x.time >> x.count >> x.break_;
    int l = 0, r = 1e7;
    vector<int> ans(n);
    while (l < r) {
        int mid = (l + r) / 2;
        int total = 0;
        vector<int> times(n);
        for (int i = 0; i < n; i++) {
            int cycle = a[i].time * a[i].count + a[i].break_;
            int cycles = mid / cycle;
            int rem = mid % cycle;
            total += cycles * a[i].count + min(a[i].count, rem / a[i].time);
            times[i] = cycles * a[i].count + min(a[i].count, rem / a[i].time);
        }
        if (total >= m) {
            ans = times;
            r = mid;
        } else {
            l = mid + 1;
        }   
    }
    cout << l << endl;
    for (int i : ans) {cout << min(i, m) << " "; m = max(0LL, m - i);}
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
