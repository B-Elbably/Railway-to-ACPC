#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, int> freq;
    int L, R;
    int l = 0, mx = 0; 
    int dis = 0;
    for (int i = 0; i < n; ++i) {
        freq[a[i]]++;
        dis += (freq[a[i]] == 1);
        while (dis > k) {
            freq[a[l]]--;
            dis -= (freq[a[l]] == 0);
            l++;
        }
        if (i - l + 1 > mx) {
            mx = i - l + 1;
            L = l; R = i;
        }
    }
    cout << L + 1 << " " << R + 1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
