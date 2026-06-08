#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(all(a));
    int s;
    cin >> s;
    int l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int j = 0, res = 0;
        while (j < n) {
            res++;
            if (mid == 0) j++;
            else j = lower_bound(all(a), a[j] + mid) - a.begin();
        }
        if (res >= s) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}