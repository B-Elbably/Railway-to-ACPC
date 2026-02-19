#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, c;
    cin >> n >> c; 
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) { 
        cin >> a[i];  sum += a[i];
    }
    if (c == 0) {
        cout << *min_element(all(a)) << endl;
        return;
    }
    int l = *min_element(all(a)) - 1, r = sum / n + 1;
    int res = l;
    while (l < r) {
        int mid = (l + r) / 2;
        vector<int> b(n);
        int mn = LLONG_MAX, idx = 0; 
        for (int i = 0; i < n; i++) {
            b[i] = min(c, a[i] - mid);
            if (b[i] < mn) {
                mn = b[i];
                idx = i;
            }
        }
        // n operations,
        int need = 0;
        for (int i = idx; i > - idx && (-need < c); --i){
            int j = (i + n) % n;
            need += b[j];
            need = min(need, c);
        }
        if (need >= 0) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
