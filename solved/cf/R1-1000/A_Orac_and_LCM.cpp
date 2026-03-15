#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 2e5 + 5;
vector<int> spf(N, 0);

void build() {
    for (int i = 1; i < N; i++) spf[i] = i;
    for (int i = 2; i * i < N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < N; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, int> freq;
    map<int, pair<int, int>> freq2;
    
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        while (x > 1) {
            int p = spf[x];
            int cnt = 0;
            freq[p]++;
            while (x % p == 0) { x /= p; cnt++; }
            
            if (!freq2.count(p)) {
                freq2[p] = {cnt, 1e9};
            } else {
                if (cnt <= freq2[p].first) {
                    freq2[p].second = freq2[p].first;
                    freq2[p].first = cnt;
                } else if (cnt < freq2[p].second) {
                    freq2[p].second = cnt;
                }
            }
        }
    }
    
    int ans = 1;
    for (auto &[p, count] : freq) {
        if (count < n - 1) continue;
        int pwr = (count == n) ? freq2[p].second : freq2[p].first;
        while (pwr--) ans *= p;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    int t = 1;
    while (t--) solve();
}