#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int sum;
int brute(int n, vector<int> &a) {
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        int s = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                s += a[j];
            }
        }
        if (s == sum - 1) ans++;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sum = accumulate(all(a), 0LL);
    // cout << brute(n, a) << endl;
    // return;
    
    int ones = 0, zeros = 0;
    for (int x : a) {
        ones += x == 1;
        zeros += x == 0;
    } 
    if (!zeros) {
        cout << ones << endl;
        return;
    }
    if (!ones) {
        cout << 0 << endl;
        return;
    }
    int ans = ones * (1LL << (zeros));
    cout << ans << endl;
    // // cout << ones << " " << zeros << endl;
    // int ans = ones * (zeros * (zeros + 1) / 2);
    // cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
