#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void fwht(vector<long long>& a, bool inv) {
    int n = a.size();
    for (int len = 1; 2 * len <= n; len <<= 1) {
        for (int i = 0; i < n; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                long long u = a[i + j];
                long long v = a[i + len + j];
                a[i + j] = u + v;
                a[i + len + j] = u - v;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < n; i++) {
            a[i] /= n;
        }
    }
}
const int N = 1 << 20;

void solve() {
    int n;
    cin >> n;
    vector<int> freq(N, 0);
    int pref = 0;
    freq[0] = 1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        pref ^= x;
        freq[pref]++;
    }

    fwht(freq, false);
    for (int &x : freq) x *= x;
    fwht(freq, true);
    vector<int> ans;
    if (freq[0] > n + 1) ans.push_back(0);
    for (int x = 1; x < N; ++x) {
        if (freq[x])
            ans.push_back(x);
    }
    cout << ans.size() << endl;
    for (int x : ans)
        cout << x << ' ';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
